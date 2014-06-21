/*
 * Font.cpp
 *
 *  Created on: 21.06.2014
 *      Author: Jonas
 */

#include "Font.h"
#include <iostream>
#include <fstream>

using namespace std;

Font::Font(Sprite* font_sprite, string charPath):
	sprite_(font_sprite),
	char_width_(0),
	char_height_(0),
	chars_per_row_(0),
	size_(1){
		ifstream datei(charPath);
		if(!datei){
			cerr << "Error while loading font!" << endl;
		}
		string line;
		size_t lines = 0;
		while(getline(datei, line)){
			if(line.length() > chars_per_row_){
				chars_per_row_ = line.length();
			}
			for(char c : line){
				chars_.push_back(c);
			}
			++lines;
		}

		char_width_ = sprite_->getWidth()/((float)chars_per_row_);
		char_height_ = sprite_->getHeight()/((float)lines)

	;
}

Font::~Font(){

}

void Font::draw_text(Vec2 pos, string text) const{
	static const float w = ((float)char_width_)/sprite_->getWidth();
	static const float h = ((float)char_height_)/sprite_->getHeight();
	for(size_t i=0; i<text.length(); i++){
		Vec2 c_pos = getPositionOfChar(text[i]);
		if(c_pos.getX() == -1){
			continue;
		}
		float wi = c_pos.getX();
		float hi = c_pos.getY();
		pos += Vec2(char_width_*size_, 0);
		sprite_->draw(pos, Vec2(char_width_*size_, char_height_*size_), Vec2(wi*w,hi*h), Vec2((wi+1)*w,(hi+1)*h));
	}

}

Vec2 Font::getPositionOfChar(char c) const{
	for(size_t i=0; i< chars_.size(); i++){
		if(chars_[i] == c){
			return Vec2(i % chars_per_row_, i / chars_per_row_);
		}
	}
	return Vec2(-1,-1);
}

void Font::setColor(Color c){
	sprite_->setColor(c);
}

void Font::setSize(float s){
	size_ = s;
}

