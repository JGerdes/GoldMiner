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
		this->destination_.getY()+= 2;
	}
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_LEFT)) {
		this->destination_.getX()-= 2;
	}
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_UP)) {
		this->destination_.getY() += 2;
	}


	//-----UPDATE POSITION -------

	this->position_ += (this->destination_ - this->position_) /= 10.0;

	this->draw();

	//------GRAVTIY-------




}
