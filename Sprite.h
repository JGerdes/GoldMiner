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
#include <GLFW/glfw3.h>

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


	Sprite(unsigned int tex_handle):
		width_(0),
		height_(0),
		buffer_(new float[0]),
		tex_handle_(tex_handle),
		path_(""),
		debug_(false),
		color_(Color(1,1,1)),
		flipped_(false){
	}

	virtual ~Sprite(){
		delete[] buffer_;
	}

	bool loadFromPPM(const std::string& filename);

	void draw(const Vec2& position, const Vec2& dimension) const;

	unsigned int getWidth() const;
	unsigned int getHeight() const;
	const float* getBuffer() const;
	std::string getPath() const;
	Color& getColor();
	void flip();
	void flip(bool flipped);


private:
	unsigned int width_;
	unsigned int height_;
	float* buffer_;
	GLuint tex_handle_;
	std::string path_;
	bool debug_;
	Color color_;
	bool flipped_;
};

#endif /* SPRITE_H_ */
