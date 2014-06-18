/*
 * SpriteManager.cpp
 *
 *  Created on: 18.06.2014
 *      Author: Jonas
 */

#include "SpriteManager.h"
#include <iostream>

using namespace std;

SpriteManager::SpriteManager() {
	// TODO Auto-generated constructor stub

}

SpriteManager::~SpriteManager() {
	for(Sprite* sprite : sprites_){
		delete sprite;
	}
}

Sprite* SpriteManager::getSprite(string path){
	for(Sprite* sprite : sprites_){
		if(sprite->getPath() == path){
			return sprite;
		}
	}
	Sprite* sprite = new Sprite(sprites_.size(), Sprite::RGBA);
	if(sprite->loadFromPPM(path, Sprite::RGBA)){
		sprites_.push_back(sprite);
		return sprite;
	}else{
		//TODO: Fehlerbehandlung
		cerr << "Error while loading sprite @"<< path << endl;
		return nullptr;
	}

}
