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

void Player::setMoveables(bool canJump, bool canMoveLeft, bool canMoveRight, bool canFall){
	this->canFall_ = canFall;
	this->canJump_ = canJump;
	this->canMoveLeft_ = canMoveLeft;
	this->canMoveRight_ = canMoveRight;
}


void Player::tick() {
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_RIGHT) && this->canMoveRight_) {
		this->destination_.getX() += 10;
	}
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_LEFT)&& this->canMoveLeft_) {
		this->destination_.getX() -= 10;
	}


	//------GRAVTIY-------
	if(this->canFall_){
		this->destination_.getY() += 2;
	}

	//-----UPDATE POSITION -------

	this->position_ += (this->destination_ - this->position_) /= 10.0;


}
