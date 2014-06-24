/*
 * Sprite.h
 *
 *  Created on: 15.06.2014
 *      Author: Jonas
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include "../Vec2.h"
#include <GLFW/glfw3.h>
#include "ImageBuffer.h"

class Color{
public:
	Color(float r=0, float g=0, float b=0):
		r(r),
		g(g),
		b(b){}
	float r, g, b;
};


class Sprite {


public:

	Sprite(ImageBuffer* image_buffer);

	virtual ~Sprite(){
	}


	void draw(const Vec2& position, const Vec2& dimension) const;
	void draw(const Vec2& position, const Vec2& dimension, const Vec2& tex_start, const Vec2& tex_end) const;

	unsigned int getWidth() const;
	unsigned int getHeight() const;
	Color& getColor();
	void setColor(const Color& color);
	void flip();
	void flip(bool flipped);


private:
	ImageBuffer* image_buffer_;
	bool debug_;
	Color color_;
	bool flipped_;
};

#endif /* SPRITE_H_ */
