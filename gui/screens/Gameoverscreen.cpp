/*
 * GameOverScreen.cpp
 *
 *  Created on: 21.06.2014
 *      Author: Chris
 */

#include "GameOverScreen.h"
#include "../../Game.h"
#include <sstream>
using namespace std;

Gameoverscreen::Gameoverscreen(SpriteManager* spriteManager, bool enable) :
		Screen(spriteManager, enable),
		bg_(spriteManager->getSprite("assets/graphics/menue.ppm")),
		font_(new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")),
		text_(""),
		score_(0){
		Button *b = new Button(playAgain, spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((Game::window_width_-64*6)/2.0,200), Vec2(64*6,16*8));
		b->setFont(font_);
		b->setText("Play again!");
		buttons_.push_back(b);

		b = new Button(mainMenu, spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(Game::window_width_-32*6-20,100), Vec2(32*6,8*6));
		b->setFont(font_);
		b->setText("Main menu");
		buttons_.push_back(b);
}

Gameoverscreen::~Gameoverscreen() {
	delete bg_;
	delete font_;
	vector<Button*>::iterator iter = buttons_.begin();
	while(iter != buttons_.end()){
		delete (*iter++);
	}
}


void Gameoverscreen::tick() {

}

void Gameoverscreen::draw()const{
	bg_->draw(Vec2(0,0), Vec2(Game::window_width_,Game::window_height_));
	font_->setSize(2);
	font_->setColor(Color(0,0,0));
	for(Button* b : buttons_){
		b->draw();
	}
	font_->setColor(Color(1,1,1));
	font_->setSize(4);
	font_->draw_text(Vec2((Game::window_width_-font_->compute_dimension(text_).getX())/2, 400), text_);
	stringstream scoreText;
	scoreText << "Score: " << score_;
	font_->setSize(2);
	font_->draw_text(Vec2((Game::window_width_-font_->compute_dimension(scoreText.str()).getX())/2, 350), scoreText.str());
}

void Gameoverscreen::setEnabled(bool enable){
	Screen::setEnabled(enable);
	for(Button* b : buttons_){
		b->setVisible(enable);
	}
}

vector<Button*>& Gameoverscreen::getButtons(){
	return buttons_;
}

void Gameoverscreen::setText(std::string text){
	text_ = text;
}

void Gameoverscreen::setScore(int score){
	score_ = score;
}
