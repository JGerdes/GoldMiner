/*
 * Sprite.cpp
 *
 *  Created on: 15.06.2014
 *      Author: Jonas
 */

#include "Sprite.h"

#include <fstream>
#include <iostream>


using namespace std;

bool Sprite::loadFromPPM(const string& filename){
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
	buffer_temp = new float[width_*height_*4];
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

			//TODO: use other color for transparent pixel instead of black
		if(r==0 && g==0 && b==0){
			buffer_temp[4*i+3] =0;
		}else{
			buffer_temp[4*i+3] =1;
		}
	}
	if(buffer_ != nullptr){
		delete[] buffer_;
	}
	buffer_ = buffer_temp;
	path_ = filename;

	glGenTextures(1, &tex_handle_);
	glBindTexture(GL_TEXTURE_2D, tex_handle_);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_FLOAT, buffer_);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

	cout << "load sprite :"<< path_ << endl;
	cout << "TextHandle load: [" << tex_handle_<< "]" << endl;


	return true;
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

string Sprite::getPath() const{
	return path_;
}


void Sprite::draw(const Vec2& position, const Vec2& dimension) const{


	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(position.getX(), position.getY(), 0);
	glBindTexture(GL_TEXTURE_2D, tex_handle_);

	glBegin(GL_QUADS);
		glColor3f(1,1,1);
		glTexCoord2d(1.0f, 0.0f);
		glVertex2d( dimension.getX(),  dimension.getY());
		glTexCoord2d(0.0f, 0.0f);
		glVertex2d(0.0, dimension.getY());
		glTexCoord2d(0.0f, 1.0f);
		glVertex2d( 0.0,0.0);
		glTexCoord2d(1.0f, 1.0f);
		glVertex2d( dimension.getX(), 0);
	glEnd();

	if(debug_){
		glDisable(GL_TEXTURE_2D);
		glLineWidth(3);
		glBegin(GL_LINES);
			glColor3f(0,1,0);
			glVertex2d(0,0);
			glVertex2d(dimension.getX(),0);
			glColor3f(1,0,0);
			glVertex2d(0,dimension.getY());
			glVertex2d(dimension.getX(),dimension.getY());
			glColor3f(0,0,1);
			glVertex2d(0,0);
			glVertex2d(0,dimension.getY());
			glColor3f(1,1,0);
			glVertex2d(dimension.getX(),0);
			glVertex2d(dimension.getX(),dimension.getY());
		glEnd();
	}
	glPopMatrix();
}
