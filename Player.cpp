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

void Player::onKeyDown(int key) {
	if (key == GLFW_KEY_W && this->top_ != nullptr) {
		this->destination_.getY() += 80;
	}
	if (key == GLFW_KEY_LEFT) {
		this->left_->mine();
	}
	if (key == GLFW_KEY_RIGHT) {
		this->right_->mine();
	}
	if (key == GLFW_KEY_UP) {
		this->top_->mine();
	}
	if (key == GLFW_KEY_DOWN) {
		this->bottom_->mine();
	}
}

void Player::onKeyUp(int key) {

}

void Player::setNearestBlocks(Block* top, Block* left, Block* right, Block* bottom) {
	this->bottom_ = bottom;
	this->top_ = top;
	this->left_ = left;
	this->right_ = right;
}

void Player::tick() {
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_D)&& this->right_ == nullptr) {
		this->destination_.getX() += 5;
	}
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_A) && this->left_ == nullptr) {
		this->destination_.getX() -= 5;
	}

	//------GRAVTIY-------
	if (this->bottom_ == nullptr) {
		this->destination_.getY() -= 2;
	}

	//-----UPDATE POSITION -------

	this->position_ += (this->destination_ - this->position_) /= 10.0;

}
