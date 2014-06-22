/*
 * SpriteManager.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonas
 */

#ifndef SPRITEMANAGER_H_
#define SPRITEMANAGER_H_

#include <vector>
#include <string>
#include "Sprite.h"
#include "ImageBuffer.h"

class SpriteManager {
public:

	SpriteManager();
	virtual ~SpriteManager();

	Sprite* getSprite(std::string path);

private:
	std::vector<ImageBuffer*> image_buffers_;
	std::vector<Sprite*> sprites_;
};

#endif /* SPRITEMANAGER_H_ */