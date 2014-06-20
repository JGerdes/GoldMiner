/*
 * Startscreen.cpp
 *
 *  Created on: 20.06.2014
 *      Author: Chris
 */

#include <iostream>
#include <string>
#include "Startscreen.h"
#include "InputManager.h"
#include "Entity.h"

using namespace std;

Startscreen::Startscreen(Sprite* sprite, Vec2 position, Vec2 dimension) :
		Entity(sprite, position, dimension), startLevelOne(false), startLevelTwo(
				false), showHighscore(false) {
	InputManager::getInstance().addMouseListener(this);
}

Startscreen::~Startscreen() {

}

void Startscreen::onButtonDown(int button, Vec2 screen_pos) {
	if (startLevelOne == false && startLevelTwo == false
			&& showHighscore == false) {
		if (button == GLFW_MOUSE_BUTTON_1) {
			if (screen_pos.getX() > 1280.0 / 4
					&& screen_pos.getX() < 1280.0 / 4 * 3
					&& screen_pos.getY() > 720.0 / 8 * 3
					&& screen_pos.getY() < 720.0 / 8 * 4) {
				startLevelOne = true;
			}
			if (screen_pos.getX() > 1280.0 / 4
					&& screen_pos.getX() < 1280.0 / 4 * 3
					&& screen_pos.getY() > 720.0 / 8 * 4
					&& screen_pos.getY() < 720.0 / 8 * 5) {
				startLevelTwo = true;
			}
			if (screen_pos.getX() > 1280.0 / 4
					&& screen_pos.getX() < 1280.0 / 4 * 3
					&& screen_pos.getY() > 720.0 / 8 * 6
					&& screen_pos.getY() < 720.0 / 8 * 7) {
				showHighscore = true;
			}
		}
	}
}

void Startscreen::onMouseMove(Vec2 screen_pos, Vec2 delta) {

}

void Startscreen::onScroll(Vec2 offset) {

}

void Startscreen::onButtonUp(int button, Vec2 screen_pos) {

}

void Startscreen::drawBg() {
	this->draw();
}

bool Startscreen::isLevelOneStarting() const {
	return startLevelOne;
}

bool Startscreen::isLevelTwoStarting() const {
	return startLevelTwo;
}


bool Startscreen::isHighscoreKlicked() const{
	return showHighscore;
}

void Startscreen::setLevelOff() {
	startLevelOne = false;
	startLevelTwo = false;
	showHighscore = false;
}

void Startscreen::tick() {

}
