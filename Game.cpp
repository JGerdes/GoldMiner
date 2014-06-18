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
		world_(new World(sprite_manager_)){ //

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

}


void Game::run() {

	cout << "run" << endl;
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


	cout << "render" << endl;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, window_width_, 0, window_height_, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

//	static Sprite sprite(1, Sprite::RGBA);
//	sprite.loadFromPPM("assets/graphics/mario.ppm", Sprite::RGBA);
//	sprite.draw(Vec2(0,0), Vec2(100,100));
	world_->draw();

}
