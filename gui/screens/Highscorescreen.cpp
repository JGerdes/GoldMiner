/*
 * Highscorescreen.cpp
 *
 *  Created on: 23.06.2014
 *      Author: Jonathan
 */

#include "Highscorescreen.h"
#include "Startscreen.h"
#include <sstream>


using namespace std;


Highscorescreen::Highscorescreen(SpriteManager* spriteManager, bool enable):
	Screen(spriteManager, enable),
	font_(new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")),
	bg_(spriteManager->getSprite("assets/graphics/menue.ppm")){

	Button* b = new Button(Startscreen::backButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(1280-32*6-20,100), Vec2(32*6,8*6));
	b->setFont(font_);
	b->setText("back");
	buttons_.push_back(b);
}

Highscorescreen::~Highscorescreen() {
	delete font_;
	delete bg_;
}

void Highscorescreen::setEnabled(bool enable){
	Screen::setEnabled(enable);
	for(Button* b : buttons_){
		b->setVisible(enable);
	}
}

void Highscorescreen::setHighscores(std::vector<unsigned int> level_1, std::vector<unsigned int> level_2){
	stringstream s;
	for(auto h: level_1){
		s << h;
		level_1_.push_back(s.str());
		s.str("");
	}

	for(auto h: level_2){
		s << h;
		level_2_.push_back(s.str());
		s.str("");
	}
}




void Highscorescreen::draw()const{
	font_->draw_text(Vec2(600,300),"Highscors");

	for()
}

void Highscorescreen::tick(){

}
