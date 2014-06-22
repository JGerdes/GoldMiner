/*
 * ImageBuffer.cpp
 *
 *  Created on: 20.06.2014
 *      Author: Jonas
 */

#include "ImageBuffer.h"
#include <iostream>
#include <fstream>

using namespace std;

ImageBuffer::ImageBuffer():
	buffer_(nullptr),
	width_(0),
	height_(0),
	tex_handle_(-1),
	path_("")
	{


}

ImageBuffer::~ImageBuffer() {
	if(buffer_ != nullptr){
		delete[] buffer_;
	}
}

bool ImageBuffer::loadFromPPM(const string& filename){
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

unsigned int ImageBuffer::getWidth() const{
	return width_;
}

unsigned int ImageBuffer::getHeight() const{
	return height_;
}

const string& ImageBuffer::getPath() const{
	return path_;
}

GLuint ImageBuffer::getTexHandle() const{
	return tex_handle_;
}
