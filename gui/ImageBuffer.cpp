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
	/**
	 * Der höchste Wert den eine Farbe des Pixels erreichen kann.
	 * Steht im header der PPM
	 */
	datei >> bitsPerPixel;


	float* buffer_temp;
	buffer_temp = new float[width_*height_*4];
	for(unsigned int i=0; i< width_*height_; i++){
		float r;
		float g;
		float b;
		datei >> r;
		datei >> g;
		datei >> b;
		/*
		 * Da in der einer PPM Datei normalerweise alle Farben mit werten von 0 bis 255 angegeben sind
		 * und OpenGL nur Farben im bereich 0 - bis 1 verarbeitet
		 * wird hier durch den höchstmöglichen Wert geteilt.
		 */
		buffer_temp[4*i+0] = r/bitsPerPixel;
		buffer_temp[4*i+1] = g/bitsPerPixel;
		buffer_temp[4*i+2] = b/bitsPerPixel;

		/*
		 * Wenn ein Pixel in der PPM schwarz ist, wird er Transparent dargestellt.
		 */
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

	/*
	 * Um mit OpenGL Texturen darzustellen muss man der textur zuerst einen "Namen" geben.
	 * Dieser wird in dem eindimensionalen Array tex_handle_ gespeichert.
	 * Um zu garantieren das dieser "Name" nicht mehr verwendet wird, muss das tex_handle_ an ein Ziel gebuden werden.
	 * In diesem Fall als 2D Texture.
	 * Sollte der "Name" vorher schon einmal an ein Ziel gebunden worden sein, wird die vorherige Verbindung durch ein erneutes binden zerstört.
	 */
	glGenTextures(1, &tex_handle_);
	glBindTexture(GL_TEXTURE_2D, tex_handle_);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width_, height_, 0, GL_RGBA, GL_FLOAT, buffer_);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameterf(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);

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
