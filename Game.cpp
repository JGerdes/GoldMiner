/*
 * Game.cpp
 *
 *  Created on: 13.06.2014
 *      Author: Jonas
 */

#include "Game.h"
#include <iostream>
#include "Vec2.h"
#include "InputManager.h"
#include "Highscore.h"


using namespace std;

Game::Game(double width = 1280, double height = 720) :
		window_(nullptr),
		window_width_(width),
		window_height_(height),
		sprite_manager_(new SpriteManager()),
		world_(nullptr),
		startscreen_(nullptr),
		gamestate(menue),
		exit(false){ //
	InputManager::getInstance().addKeyListener(this);
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

void Game::onKeyDown(int key) {
	if(gamestate != menue) {
		if(key == GLFW_KEY_ESCAPE) {
			gamestate = menue;
			startscreen_->setLevelOff();
		}
	}
	else
		if(key == GLFW_KEY_ESCAPE) {
			exit = true;
		}
}

void Game::onKeyUp(int key) {

}

Game::~Game() {
	delete world_;
	delete startscreen_;
}

void Game::init() {

	cout << "init" << endl;

	glViewport(0, 0, window_width_, window_height_);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

	//Callbacks bei GLFW registrieren
	glfwSetCursorPosCallback(window_, &InputManager::onMouseMove);
	glfwSetMouseButtonCallback(window_, &InputManager::onButton);
	glfwSetKeyCallback(window_, &InputManager::onKey);
	glfwSetScrollCallback(window_, &InputManager::onScroll);

	startscreen_ = new Startscreen(sprite_manager_->getSprite("assets/graphics/menue.ppm"), Vec2(0, 0), Vec2(1280.0, 720.0));
	world_ = new World(sprite_manager_, "map.txt");
	world1_ = new World(sprite_manager_, "map2.txt");
	highscore = new Highscore();
}


void Game::run() {
	glfwSetTime(0);
	static unsigned int i = 0;
	cout << "run" << endl;
	while (!glfwWindowShouldClose(window_) && exit == false) {

		if(gamestate == menue) {
			startscreen_->tick();
			if(startscreen_->isLevelOneStarting()) {
				gamestate = runningLevelOne;
			}
			if(startscreen_->isLevelTwoStarting()) {
				gamestate = runningLevelTwo;
			}
			if(startscreen_->isHighscoreKlicked()) {
				//TODO anzeige der Highscore (nicht Konsole)
				highscore->setHighscore(1);
				startscreen_->setLevelOff();
			}
		}

		if(gamestate == runningLevelTwo) {
			world1_->getPlayer()->setVisible(true);
			world_->getPlayer()->setVisible(false);
			world1_->tick();
		}

		if(gamestate == runningLevelOne)
			world1_->getPlayer()->setVisible(false);
			world_->getPlayer()->setVisible(true);
			world_->tick();

		glClearColor(0.7, 0.8, 1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		render();


		i++;
		if(glfwGetTime() > 1){
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

	if(gamestate == menue)
		startscreen_->draw();
	if(gamestate == runningLevelOne)
		world_->draw();
	if(gamestate == runningLevelTwo)
		world1_->draw();
}
