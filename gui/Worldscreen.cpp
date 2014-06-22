/*
 * Worldscreen.cpp
 *
 *  Created on: 22.06.2014
 *      Author: Jonathan
 */

#include "Worldscreen.h"

using namespace std;


Worldscreen::Worldscreen(SpriteManager* spriteManager):
	Screen(spriteManager),
	world_(nullptr){

}

Worldscreen::~Worldscreen() {
	if(world_ != nullptr){
		delete world_;
	}
}


void Worldscreen::draw()const {
	if(world_ != nullptr){
		world_->draw();
	}
}

void Worldscreen::tick(){
	if(world_ != nullptr){
		world_->tick();
	}
}

void Worldscreen::setLevel(World* world){
	world_ = world;
}
