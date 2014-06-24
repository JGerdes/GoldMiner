#include "Block.h"
#include "../Game.h"
#include "../gui/Sprite.h"
#include <iostream>


Block::Block(Type type, Vec2 position, Sprite* sprite):
	Entity(sprite, position, Vec2(Game::window_width/16,Game::window_height/9)),
	type_(type),
	damage_(0),
	max_damage_(type){
}

Block::~Block() {

}

void Block::tick(){

}

void Block::mine(){
	damage_ += 1;
}

const bool Block::isDestroyed(){
	return(damage_ >= max_damage_);
}
