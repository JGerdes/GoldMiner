/*
 * Player.cpp
 *
 *  Created on: 18.06.2014
 *      Author: Jonathan
 */

#include "Player.h"
#include <iostream>

using namespace std;



Player::~Player() {
	// TODO Auto-generated destructor stub
}

void Player::onKeyDown(int key){
	if(key == GLFW_KEY_SPACE){
		this->destination_.getY() -= 120;
	}
}

void Player::onKeyUp(int key){

}


void Player::tick() {
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_RIGHT)) {
		this->destination_.getX() += 10;
	}
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_LEFT)) {
		this->destination_.getX() -= 10;
	}


	//------GRAVTIY-------

	this->destination_.getY() += 1;

	//-----UPDATE POSITION -------

	this->position_ += (this->destination_ - this->position_) /= 10.0;


}
