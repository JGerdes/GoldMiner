/*
 * Game.cpp
 *
 *  Created on: 13.06.2014
 *      Author: Jonas
 */

#include "Game.h"
#include <iostream>
#include "Vec2.h"
#include "gui/io/InputManager.h"
#include "gui/Highscore.h"
#include "gui/GameOverScreen.h"

using namespace std;

Game::Game(double width = 1280, double height = 720) :
		window_(nullptr), window_width_(width), window_height_(height), sprite_manager_(
				new SpriteManager()) {
	cout << "Game started" << endl;

	if (!glfwInit()) {
		cerr << "Couln't initiate GLFW!" << endl;
		return;
	}
	glfwWindowHint(GLFW_SAMPLES, 16);
	window_ = glfwCreateWindow(window_width_, window_height_, "GoldMiner", NULL,
	NULL);

	if (window_ == nullptr) {
		glfwTerminate();
		cerr << "Window couln't be initiated! (is nullptr)" << endl;
		return;
	}

	glfwMakeContextCurrent(window_);
	init();
	run();

}



Game::~Game() {
	vector<Screen*>::iterator iter = screens_.begin();
	while (iter != screens_.end()) {
		delete (*iter++);
	}
}

void Game::init() {

	cout << "init" << endl;

	glViewport(0, 0, window_width_, window_height_);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Callbacks bei GLFW registrieren
	glfwSetCursorPosCallback(window_, &InputManager::onMouseMove);
	glfwSetMouseButtonCallback(window_, &InputManager::onButton);
	glfwSetKeyCallback(window_, &InputManager::onKey);
	glfwSetScrollCallback(window_, &InputManager::onScroll);

	Startscreen* start = new Startscreen(sprite_manager_, true, true);
	cout << "Button_1" << endl;
	for(Button* b : start->getButtons()){
		b->setHandler(this);
	}

	this->screens_.push_back(start);
	this->screens_.push_back(new Worldscreen(sprite_manager_,false));
//	this->screens.push_back(new Gameoverscreen(sprite_manager_));
//	this->screens.push_back(new Heighscorscreen(sprite_manager_));

	currentScreen_ = screens_.at(startscreen);
}

void Game::run() {
	glfwSetTime(0);
	static unsigned int i = 0;
	cout << "run" << endl;
	while (!glfwWindowShouldClose(window_)) {

		currentScreen_->tick();

		glClearColor(0.7, 0.8, 1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		render();

		i++;
		if (glfwGetTime() > 1) {
			cout << "Zeit: " << glfwGetTime() << " frames: " << i << endl;
			glfwSetTime(0);
			i = 0;
		}
		glfwSwapBuffers(window_);
		glfwPollEvents();
	}

	glfwTerminate();
}

void Game::render() {

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, window_width_, 0, window_height_, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	currentScreen_->draw();

}

void Game::onButtonClick(unsigned int id) {
	// startscreen buttons
	if(screens_.at(startscreen)->isEnabled()){
		if(Startscreen::levelOneButton == id){
			((Worldscreen*)screens_.at(worldscreen))->setWorld(new World(sprite_manager_, "assets/levels/map.txt"));
			((Startscreen*)screens_.at(startscreen))->setDrawMenuButtons(false);
			cout << "levelOneButton" << endl;
		}
		if(Startscreen::levelTwoButton == id){
			((Worldscreen*)screens_.at(worldscreen))->setWorld(new World(sprite_manager_, "assets/levels/map2.txt"));
			((Startscreen*)screens_.at(startscreen))->setDrawMenuButtons(false);
			cout << "levelTwoButton" << endl;
		}
		if(Startscreen::highScoreButton == id){
			screens_.at(startscreen)->setEnabled(false);
		}
		if(Startscreen::exitButton == id){
			screens_.at(startscreen)->setEnabled(false);
		}

		if(Startscreen::easyButton == id){
			screens_.at(startscreen)->setEnabled(false);
			currentScreen_ = screens_.at(worldscreen);
			cout << "easyButton" << endl;
		}
		if(Startscreen::normalButton == id){

		}
		if(Startscreen::hardButton == id){

		}
		if(Startscreen::backButton == id){
			((Startscreen*)screens_.at(startscreen))->setDrawMenuButtons(true);
		}
	}
}
