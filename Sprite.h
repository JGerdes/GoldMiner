/*
 * Sprite.h
 *
 *  Created on: 15.06.2014
 *      Author: Jonas
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include "Vec2.h"

class Sprite {
public:
	enum Type{RGB = 3, RGBA = 4};


	Sprite(unsigned int tex_handle, Type type = RGB):
		type_(type),
		width_(0),
		height_(0),
		buffer_(new float[0]),
		tex_handle_(tex_handle),
		path_(""){
	}

	virtual ~Sprite(){
		delete[] buffer_;
	}

	bool loadFromPPM(const std::string& filename, Type type);

	void draw(const Vec2& position, const Vec2& dimension) const;

	unsigned int getWidth() const;
	unsigned int getHeight() const;
	const float* getBuffer() const;
	std::string getPath() const;


private:
	Type type_;
	unsigned int width_;
	unsigned int height_;
	float* buffer_;
	unsigned int tex_handle_;
	std::string path_;
};

#endif /* SPRITE_H_ */
