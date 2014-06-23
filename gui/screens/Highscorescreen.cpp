/*
 * Highscorescreen.cpp
 *
 *  Created on: 23.06.2014
 *      Author: Jonathan
 */

#include "Highscorescreen.h"
#include "Startscreen.h"


Highscorescreen::Highscorescreen(SpriteManager* spriteManager, bool enable):
	Screen(spriteManager, enable),
	font_(new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")),
	bg_(spriteManager->getSprite("assets/graphics/menue.ppm")),
	highscore_(nullptr){

	Button* b = new Button(Startscreen::backButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(1280-32*6-20,100), Vec2(32*6,8*6));
	b->setFont(font_);
	b->setText("back");
	buttons_.push_back(b);
}

Highscorescreen::~Highscorescreen() {
	if(highscore_ != nullptr){
		delete highscore_;
	}
	delete font_;
	delete bg_;
}

void Highscorescreen::setEnabled(bool enable){
	Screen::setEnabled(enable);
	for(Button* b : buttons_){
		b->setVisible(enable);
	}
}

void Highscorescreen::setHighscore(Highscore* h){
	highscore_ = h;
}


void Highscorescreen::draw()const{

}

void Highscorescreen::tick(){

}
