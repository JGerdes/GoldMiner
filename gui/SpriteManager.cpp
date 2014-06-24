#include "SpriteManager.h"
#include <iostream>

using namespace std;

SpriteManager::SpriteManager() {}

SpriteManager::~SpriteManager() {
	vector<ImageBuffer*>::iterator iter = image_buffers_.begin();
	while(iter != image_buffers_.end()){
		delete (*iter++);
	}
	vector<Sprite*>::iterator ator = sprites_.begin();
	while(ator != sprites_.end()){
		delete (*ator++);
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
