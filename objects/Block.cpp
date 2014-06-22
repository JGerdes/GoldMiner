/*
 * Block.cpp
 *
 *  Created on: 18.06.2014
 *      Author: Jonas
 */

#include "Block.h"
#include "../gui/Sprite.h"
#include <iostream>


Block::Block(Type type, Vec2 position, Sprite* sprite, unsigned int max_damage):
	Entity(sprite, position, Vec2(1280.0/16,720.0/9)),
	type_(type),
	damage_(0),
	max_damage_(max_damage){


}

Block::~Block() {

}

void Block::tick(){
	//TODO: do stuff
}

void Block::mine(){
	damage_ += 1;
	std::cout << "Damage:" << damage_ << std::endl;

}

bool Block::isDestroyed(){
	return(damage_ >= max_damage_);
}
