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
		Screen(spriteManager, new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt"), spriteManager->getSprite("assets/graphics/menue.ppm"), enable ),
		text_(""),
		score_(0){
		Button *b = new Button(playAgain, spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((Game::window_width-64*6)/2.0,200), Vec2(64*6,16*8));
		b->setText("Play again!");
		b->setFont(font_);
		buttons_.push_back(b);

		b = new Button(mainMenu, spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(Game::window_width-32*6-20,100), Vec2(32*6,8*6));
		b->setFont(font_);
		b->setText("Main menu");
		buttons_.push_back(b);
}

Gameoverscreen::~Gameoverscreen() {
}


void Gameoverscreen::tick() {

}

void Gameoverscreen::draw()const{
	bg_->draw(Vec2(0,0), Vec2(Game::window_width,Game::window_height));
	font_->setSize(2);
	font_->setColor(Color(0,0,0));
	for(Button* b : buttons_){
		b->draw();
	}
	font_->setColor(Color(1,1,1));
	font_->setSize(4);
	font_->draw_text(Vec2((Game::window_width-font_->compute_dimension(text_).getX())/2, 400), text_);
	stringstream scoreText;
	scoreText << "Score: " << score_;
	font_->setSize(2);
	font_->draw_text(Vec2((Game::window_width-font_->compute_dimension(scoreText.str()).getX())/2, 350), scoreText.str());
}

void Gameoverscreen::setText(std::string text){
	text_ = text;
}

void Gameoverscreen::setScore(int score){
	score_ = score;
}
