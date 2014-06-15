/*
 * Game.cpp
 *
 *  Created on: 13.06.2014
 *      Author: Jonas
 */

#include "Game.h"
#include <iostream>

using namespace std;

Game::Game(double width = 1280, double height = 720) :
		window_(nullptr),
		window_width_(width),
		window_height_(height){

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
	// TODO Auto-generated destructor stub
}

void Game::init() {

	glViewport(0, 0, window_width_, window_height_);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);

}


void Game::run() {
	while (!glfwWindowShouldClose(window_)) {
		glClearColor(1, 1, 1, 1.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		render();

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
	//TODO: render here
}
