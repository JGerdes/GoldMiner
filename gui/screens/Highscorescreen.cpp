/*
 * Highscorescreen.cpp
 *
 *  Created on: 23.06.2014
 *      Author: Jonathan
 */

#include "Highscorescreen.h"
#include "Startscreen.h"
#include "../../Game.h"
#include <sstream>


using namespace std;


Highscorescreen::Highscorescreen(SpriteManager* spriteManager, bool enable):
	Screen(spriteManager, enable),
	font_(new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")),
	bg_(spriteManager->getSprite("assets/graphics/menue.ppm")){

	Button* b = new Button(Highscorescreen::backButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(Game::window_width-32*6-20,100), Vec2(32*6,8*6));
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
	level_1_.clear();
	level_2_.clear();
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
	bg_->draw(Vec2(0,0), Vec2(Game::window_width, Game::window_height));
	font_->setSize(4);
	font_->setColor(Color(1,1,1));
	static const string title = "Highscores";
	static const string lvl1 = "Level 1";
	static const string lvl2 = "Level 2";

	font_->draw_text(Vec2((Game::window_width-font_->compute_dimension(title).getX())/2,460),title);
	font_->setSize(3);
	font_->draw_text(Vec2(300 ,400),lvl1);
	font_->draw_text(Vec2(Game::window_width-300-font_->compute_dimension(lvl2).getX() ,400),lvl2);

	font_->setSize(2.5);
	unsigned int i=0;
	for(string score : level_1_){
		font_->draw_text(Vec2(300, 350-40*i), score);
		++i;
	}
	i=0;
	for(string score : level_2_){
		font_->draw_text(Vec2(Game::window_width-300-font_->compute_dimension(score).getX(), 350-40*i), score);
		++i;
	}

	font_->setSize(2);
	font_->setColor(Color(0,0,0));
	for(Button *b : buttons_){
		b->draw();
	}
}

void Highscorescreen::tick(){

}

vector<Button*> Highscorescreen::getButtons(){
	return buttons_;
}
