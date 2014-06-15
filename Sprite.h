/*
 * Sprite.h
 *
 *  Created on: 15.06.2014
 *      Author: Jonas
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>

class Sprite {
public:
	enum Type{RGB = 3, RGBA = 4};


	Sprite(unsigned int width = 0, unsigned int height = 0, Type type = RGB):
		type_(type),
		width_(width),
		height_(height),
		image_width_(0),
		image_height_(0),
		buffer_(new float[0]){
	}

	virtual ~Sprite(){
		delete[] buffer_;
	}

	bool loadFromPPM(const std::string& filename, Type type);

	void draw(float x, float y) const;

	void setDimensions(unsigned int width, unsigned int height);

	unsigned int getWidth() const;
	unsigned int getHeight() const;
	unsigned int getImageWidth() const;
	unsigned int getImageHeight() const;
	const float* getBuffer() const;


private:
	Type type_;
	unsigned int width_;
	unsigned int height_;
	unsigned int image_width_;
	unsigned int image_height_;
	float* buffer_;

	unsigned int nextPowerOf2(unsigned int n);
};

#endif /* SPRITE_H_ */
