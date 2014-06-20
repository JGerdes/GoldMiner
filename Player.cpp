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
	if(visible_ == true) {
	if ((key == GLFW_KEY_W || key == GLFW_KEY_SPACE) && this->bottom_ != nullptr) {
		this->destination_.getY() += 80;
	}
	if (key == GLFW_KEY_LEFT && this->left_ != nullptr) {
		this->left_->mine();
	}
	if (key == GLFW_KEY_RIGHT && this->right_ != nullptr) {
		this->right_->mine();
	}
	if (key == GLFW_KEY_UP && this->top_ != nullptr) {
		this->top_->mine();
	}
	if (key == GLFW_KEY_DOWN && this->bottom_ != nullptr) {
		this->bottom_->mine();
	}
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

void Player::setVisible(bool visible) {
	this->visible_ = visible;
}

void Player::tick() {

	if(this->position_.getX() < -100 || this->position_.getX() > 1380 || this->position_.getY() < -200){
		this->position_ = Vec2(1280 / 2, 800);
		this->destination_= Vec2(1280 / 2, 800);
	}



	if (InputManager::getInstance().isKeyDown(GLFW_KEY_D)) {
		sprite_->flip(false);
		if(this->right_ == nullptr){
			this->destination_.getX() += 3;
		}

	}
	if (InputManager::getInstance().isKeyDown(GLFW_KEY_A)) {
		sprite_->flip(true);
		if(this->left_ == nullptr){
			this->destination_.getX() -= 3;
		}
	}

	//------GRAVTIY-------
	if (this->bottom_ == nullptr) {
		this->destination_.getY() -= 3;
	}

	//-----UPDATE POSITION -------

	this->position_ += (this->destination_ - this->position_) /= 10.0;

}

const int& Player::getScore(){
	return this->score;
}

void Player::addToScore(){
	this->score +=1;
}

const int& Player::getAllDestroyedBlocks(){
	return this->destroyedBlocks;
}

void Player::addToDestroyedBlocks(){
	this->destroyedBlocks +=1;
}
