#include "Sprite.h"

#include <fstream>
#include <iostream>


using namespace std;

Sprite::Sprite(ImageBuffer* image_buffer):
				image_buffer_(image_buffer),
				debug_(false),
				color_(Color(1,1,1)),
				flipped_(false){

}

unsigned int Sprite::getWidth() const{
	return image_buffer_->getWidth();
}

unsigned int Sprite::getHeight() const{
	return image_buffer_->getHeight();
}

Color& Sprite::getColor(){
	return color_;
}


void Sprite::setColor(const Color& color){
	color_ = color;
}

void Sprite::flip(){
	flipped_ = !flipped_;
}
void Sprite::flip(bool flipped){
	flipped_ = flipped;
}



void Sprite::draw(const Vec2& position, const Vec2& dimension, const Vec2& tex_start, const Vec2& tex_end){


	glEnable(GL_TEXTURE_2D);
	glPushMatrix();
	glTranslated(position.getX(), position.getY(), 0);
	glBindTexture(GL_TEXTURE_2D, image_buffer_->getTexHandle());

	double tex_x = flipped_ ? dimension.getX() : 0.0;
	double width = flipped_ ? 0.0 : dimension.getX();
	double height = dimension.getY();

	glBegin(GL_QUADS);
		glColor3f(color_.r,color_.g,color_.b);
		glTexCoord2d(tex_end.getX(), tex_start.getY());
		glVertex2d(width , height);
		glTexCoord2d(tex_start.getX(), tex_start.getY());
		glVertex2d( tex_x, height);
		glTexCoord2d(tex_start.getX(), tex_end.getY());
		glVertex2d( tex_x, 0.0);
		glTexCoord2d(tex_end.getX(), tex_end.getY());
		glVertex2d( width, 0);
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
