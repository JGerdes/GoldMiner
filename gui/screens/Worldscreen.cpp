/*
 * Worldscreen.cpp
 *
 *  Created on: 22.06.2014
 *      Author: Jonathan
 */

#include "Worldscreen.h"

using namespace std;


Worldscreen::Worldscreen(SpriteManager* spriteManager, bool enable):
	Screen(spriteManager, new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt"), spriteManager->getSprite("assets/graphics/menue.ppm"), enable),
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

void Worldscreen::setWorld(World* world){
	world_ = world;
}

World* Worldscreen::getWorld(){
	return world_;
}
