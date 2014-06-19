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


using namespace std;

Game::Game(double width = 1280, double height = 720) :
		window_(nullptr),
		window_width_(width),
		window_height_(height),
		sprite_manager_(new SpriteManager()),
		world_(nullptr){ //

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
	delete world_;
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

	world_ = new World(sprite_manager_);
}


void Game::run() {
	glfwSetTime(0);
	static unsigned int i = 0;
	cout << "run" << endl;
	while (!glfwWindowShouldClose(window_)) {

		world_->tick();

		glClearColor(1, 1, 1, 1.0);
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

	world_->draw();
}
