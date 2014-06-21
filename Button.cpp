/*
 * Button.cpp
 *
 *  Created on: 21.06.2014
 *      Author: Jonas
 */

#include "Button.h"
#include "InputManager.h"
#include <iostream>

Button::Button(unsigned int id, Sprite* sprite, Vec2 position, Vec2 dimension):
	Entity(sprite, position, dimension),
	id_(id),
	isHovered_(false),
	handler_(nullptr){
	InputManager::getInstance().addMouseListener(this);
}

Button::~Button(){

}
void Button::onMouseMove(Vec2 screen_pos, Vec2 delta){
	bool x = screen_pos.getX() > position_.getX() && screen_pos.getX() < position_.getX() + dimension_.getX();
	bool y = screen_pos.getY() > position_.getY() && screen_pos.getY() < position_.getY() + dimension_.getY();
	isHovered_ = x && y;

}
void Button::onButtonUp(int button, Vec2 screen_pos){

}
void Button::onButtonDown(int button , Vec2 screen_pos){
	bool x = screen_pos.getX() > position_.getX() && screen_pos.getX() < position_.getX() + dimension_.getX();
	bool y = screen_pos.getY() > position_.getY() && screen_pos.getY() < position_.getY() + dimension_.getY();
	if(x && y && handler_ != nullptr){
		handler_->onButtonClick(id_);
	}

}
void Button::onScroll(Vec2 offset){

}

void Button::draw(){
	sprite_->draw(position_,dimension_,isHovered_ ? Vec2(0.5,0) : Vec2(0,0), isHovered_ ? Vec2(1,1) : Vec2(0.5,1));
}

void Button::setHandler(ButtonHandler* handler){
	handler_ = handler;
}
