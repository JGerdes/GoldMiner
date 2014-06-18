/*
 * Player.cpp
 *
 *  Created on: 18.06.2014
 *      Author: Jonathan
 */

#include "Player.h"

Player::~Player() {
	// TODO Auto-generated destructor stub
}


void Player::tick() {
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_RIGHT)) {
		this->destination_.getX() += 1;
	}
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_LEFT)) {
		this->destination_.getX() -= 1;
	}
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_UP)) {
		this->destination_.getY() += 1;
	}

	//------GRAVTIY-------

//	this->destination_.getY() -= 5;

	this->position_ += (this->destination_ - this->position_) /= 10.0;

	//-----UPDATE POSITION -------

	this->position_ += (this->destination_ - this->position_) /= 10.0;


}
