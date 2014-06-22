/*
 * GameOverScreen.cpp
 *
 *  Created on: 21.06.2014
 *      Author: Chris
 */

#include "GameOverScreen.h"

GameOverScreen::GameOverScreen(Sprite* sprite, Vec2 position, Vec2 dimension) :
		Entity(sprite, position, dimension), isGameOver(false) {
	InputManager::getInstance().addMouseListener(this);
}

GameOverScreen::~GameOverScreen() {

}

bool GameOverScreen::onButtonDown(int button, Vec2 screen_pos) {
	if (isGameOver == true){
		if (button == GLFW_MOUSE_BUTTON_1) {
			isGameOver = false;
		}
	}
	return false;
}

void GameOverScreen::setGameOver(bool gameOver) {
	isGameOver = gameOver;
}

bool GameOverScreen::getIsGameOver() {
	return isGameOver;
}

void GameOverScreen::onMouseMove(Vec2 screen_pos, Vec2 delta) {

}

void GameOverScreen::onScroll(Vec2 offset) {

}

void GameOverScreen::onButtonUp(int button, Vec2 screen_pos) {

}

void GameOverScreen::tick() {

}
