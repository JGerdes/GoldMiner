/*
 * Sprite.cpp
 *
 *  Created on: 15.06.2014
 *      Author: Jonas
 */

#include "Sprite.h"

#include <fstream>
#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

bool Sprite::loadFromPPM(const string& filename, Type type){
	type_ = type;
	ifstream datei(filename);
	if(!datei){
		return false;
	}
	string s;
	float bitsPerPixel;
	getline(datei,s);
	datei >> width_;
	datei >> height_;
	datei >> bitsPerPixel;


	float* buffer_temp;
	buffer_temp = new float[width_*height_*type_];
	for(unsigned int i=0; i< width_*height_; i++){
		float r;
		float g;
		float b;
		//value = (datei.get()); //for binary (TODO ?)
		datei >> r;
		datei >> g;
		datei >> b;

		buffer_temp[4*i+0] = r/bitsPerPixel;
		buffer_temp[4*i+1] = g/bitsPerPixel;
		buffer_temp[4*i+2] = b/bitsPerPixel;

		if(type_ == RGBA){
			//TODO: use other color for transparent pixel instead of black
			if(r==0 && g==0 && b==0){
				buffer_temp[4*i+3] =0;
			}else{
				buffer_temp[4*i+3] =1;
			}
		}
	}
	if(buffer_ != nullptr){
		delete[] buffer_;
	}
	buffer_ = buffer_temp;
	return true;
}


unsigned int Sprite::getImageWidth() const{
	return image_width_;
}

unsigned int Sprite::getImageHeight() const{
	return image_height_;
}

unsigned int Sprite::getWidth() const{
	return width_;
}

unsigned int Sprite::getHeight() const{
	return height_;
}

const float* Sprite::getBuffer() const{
	return buffer_;
}

unsigned int Sprite::nextPowerOf2(unsigned int n){
	n--;
	n |= n >> 1;
	n |= n >> 2;
	n |= n >> 4;
	n |= n >> 8;
	n |= n >> 16;
	n++;
	return n;
}


void Sprite::draw(float x, float y) const{
	glPushMatrix();
	glTranslatef(x, y, 0);
	GLuint texHandle = 1;
	glGenTextures(1, &texHandle);
	glBindTexture(GL_TEXTURE_2D, texHandle);
	int glMode = (type_== RGBA) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_2D, 0, glMode, width_, height_, 0, GL_RGBA, GL_FLOAT, buffer_);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

	glBegin(GL_QUADS);
		glTexCoord2f(1.0f, 0.0f);
		glVertex2f( 100.0,  100.0);
		glTexCoord2f(0.0f, 0.0f);
		glVertex2f(0.0, 100.0);
		glTexCoord2f(0.0f, 1.0f);
		glVertex2f( 0.0,0.0);
		glTexCoord2f(1.0f, 1.0f);
		glVertex2f( 100.0, 0.0);
	glEnd();
}
