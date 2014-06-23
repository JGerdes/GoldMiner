/*
 * Game.cpp
 *
 *  Created on: 13.06.2014
 *      Author: Jonas
 */

#include "Game.h"
#include <stdlib.h>
#include <iostream>
#include "Vec2.h"
#include "gui/io/InputManager.h"
#include <string>
#include <sstream>
#define SSTR( x ) dynamic_cast<std::ostringstream &>(( std::ostringstream() << std::dec << x ) ).str()
using namespace std;

double Game::window_width_ = 0;
double Game::window_height_ = 0;

Game::Game(double width = 1280, double height = 720) :
		window_(nullptr),
		sprite_manager_(new SpriteManager()),
		current_world_(-1){
	window_width_ = width;
	window_height_ =height;
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
	vector<Highscore*>::iterator score_iter = scores_.begin();
	while (score_iter != scores_.end()) {
		delete (*score_iter++);
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
	glfwSetWindowSizeCallback(window_, &InputManager::onResize);

	level_files_.push_back("map");
	level_files_.push_back("map2");

	for(string level_file : level_files_){
		scores_.push_back(new Highscore("assets/levels/"+ level_file+ "_highscore.txt"));
	}

	Startscreen* start = new Startscreen(sprite_manager_, true, true);
	for(Button* b : start->getButtons()){
		b->setHandler(this);
	}

	Gameoverscreen* gameover = new Gameoverscreen(sprite_manager_,false);
	for(Button* button : gameover->getButtons()){
		button->setHandler(this);
	}

	Highscorescreen* highscore = new Highscorescreen(sprite_manager_, false);
	for(Button* button : highscore->getButtons()){
		button->setHandler(this);
	}

	this->screens_.push_back(start);
	this->screens_.push_back(new Worldscreen(sprite_manager_,false));
	this->screens_.push_back(gameover);
	this->screens_.push_back(highscore);

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
			string s = "Goldminer Frames: " + SSTR(i);
			glfwSetWindowTitle(window_, s.c_str());
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

void Game::startWorld(unsigned int id) {
	current_world_ = id;
	World* world = new World(sprite_manager_, "assets/levels/"+ level_files_[id]+ ".txt");
	world->setWorldEventListener(this);
	((Worldscreen*) (screens_.at(worldscreen)))->setWorld(world);
	((Startscreen*) (screens_.at(startscreen)))->setDrawMenuButtons(false);
}

void Game::onButtonClick(unsigned int id) {
	switch(id){
		case Startscreen::levelOneButton:
			startWorld(0);
			break;
		case Startscreen::levelTwoButton:
			startWorld(1);
			break;
		case Startscreen::highScoreButton:
			currentScreen_->setEnabled(false);
			currentScreen_ = screens_.at(highscorescreen);
			((Highscorescreen*) currentScreen_)->setHighscores(scores_[0]->getTop(10), scores_[1]->getTop(10));
			currentScreen_->setEnabled(true);
			break;
		case Startscreen::exitButton:
			screens_.at(startscreen)->setEnabled(false);
			glfwTerminate();
			exit(-1);
			break;

		case Startscreen::easyButton:
			((Worldscreen*)screens_.at(worldscreen))->getWorld()->setDifficulty(World::EASY_GAME);
			screens_.at(startscreen)->setEnabled(false);
			currentScreen_ = screens_.at(worldscreen);
			break;
		case Startscreen::normalButton:
			((Worldscreen*)screens_.at(worldscreen))->getWorld()->setDifficulty(World::NORMAL_GAME);
			screens_.at(startscreen)->setEnabled(false);
			currentScreen_ = screens_.at(worldscreen);
			break;
		case Startscreen::hardButton:
			((Worldscreen*)screens_.at(worldscreen))->getWorld()->setDifficulty(World::HARD_GAME);
			screens_.at(startscreen)->setEnabled(false);
			currentScreen_ = screens_.at(worldscreen);
			break;
		case Startscreen::backButton:
			((Startscreen*)screens_.at(startscreen))->setDrawMenuButtons(true);
			break;
		case Highscorescreen::backButton:
			currentScreen_->setEnabled(false);
			currentScreen_ = screens_.at(startscreen);
			currentScreen_->setEnabled(true);
			((Startscreen*)screens_.at(startscreen))->setDrawMenuButtons(true);
			break;

		case Gameoverscreen::playAgain:
			currentScreen_->setEnabled(false);
			currentScreen_ = screens_.at(startscreen);
			currentScreen_->setEnabled(true);
			((Startscreen*)screens_.at(startscreen))->setDrawMenuButtons(true);
			startWorld(current_world_);
			break;
		case Gameoverscreen::mainMenu:
			cout << "GOS: MainMenu" << endl;
			currentScreen_->setEnabled(false);
			currentScreen_ = screens_.at(startscreen);
			currentScreen_->setEnabled(true);
			((Startscreen*)screens_.at(startscreen))->setDrawMenuButtons(true);
			break;
	}
}

void Game::onLose(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks){
	score = computeScore(score, destroyedBlocks, maxBlocks);
	((Gameoverscreen*)screens_.at(gameoverscreen))->setText("You lose!");
	((Gameoverscreen*)screens_.at(gameoverscreen))->setScore(score);
	currentScreen_->setEnabled(false);
	currentScreen_ = screens_.at(gameoverscreen);
	currentScreen_->setEnabled(true);
}

void Game::onWin(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks){
	score = computeScore(score, destroyedBlocks, maxBlocks);
	((Gameoverscreen*)screens_.at(gameoverscreen))->setText("You win!");
	((Gameoverscreen*)screens_.at(gameoverscreen))->setScore(score);
	currentScreen_->setEnabled(false);
	currentScreen_ = screens_.at(gameoverscreen);
	currentScreen_->setEnabled(true);
	scores_[current_world_]->addScore(score);

}

unsigned int Game::computeScore(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks){
	return ((float)score)/(((maxBlocks-destroyedBlocks) < 1)? 1 :(maxBlocks-destroyedBlocks))*1337;
}
