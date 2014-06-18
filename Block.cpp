/*
 * Block.cpp
 *
 *  Created on: 18.06.2014
 *      Author: Jonas
 */

#include "Block.h"
#include "Sprite.h"


Block::Block(Type type, Vec2 position, Sprite* sprite):
	Entity(*sprite, position, Vec2(100,100)),
	type_(type){
	// TODO Auto-generated constructor stub

}

Block::~Block() {
	// TODO Auto-generated destructor stub
}

void Block::onMouseMove(Vec2 screen_pos, Vec2 delta){

}

void Block::onButtonUp(int button, Vec2 screen_pos){

}

void Block::onButtonDown(int button , Vec2 screen_pos){

}

void Block::onScroll(Vec2 offset){

}
