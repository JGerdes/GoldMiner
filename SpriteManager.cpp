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
	cout << "Deleting " << image_buffers_.size() << " ImageBuffers" << endl;
	for(ImageBuffer* sprite : image_buffers_){
		delete sprite;
	}
}

Sprite* SpriteManager::getSprite(string path){
	ImageBuffer* buf = nullptr;
	for(ImageBuffer* img_buffer : image_buffers_){
		if(img_buffer->getPath() == path){
			buf = img_buffer;
		}
	}
	if(buf == nullptr){
		buf = new ImageBuffer();
		if(!(buf->loadFromPPM(path))){
			cerr << "Error while loading file: " << path << endl;
			return nullptr;
		}
		image_buffers_.push_back(buf);
	}
	Sprite* sprite = new Sprite(buf);
	sprites_.push_back(sprite);

	return sprite;

}
