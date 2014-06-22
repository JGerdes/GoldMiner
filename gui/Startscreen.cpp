/*
 * Startscreen.cpp
 *
 *  Created on: 20.06.2014
 *      Author: Chris
 */

#include <iostream>
#include <string>
#include "Startscreen.h"
#include "../objects/Entity.h"


using namespace std;

Startscreen::Startscreen(SpriteManager* spriteManager, bool enable, bool drawMenuButtons) :
		Screen(spriteManager, enable),
		font_(new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")),
		drawMenuButtons_(drawMenuButtons){

	bg_ = spriteManager->getSprite("assets/graphics/menue.ppm");
	//menu
	font_->setColor(Color(0,0,0));
	Button* b = new Button(levelOneButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,400), Vec2(64*6,16*6));
	b->setFont(font_);
	b->setText("Level 1");
	b->setVisible(true);
	menu_buttons_.push_back(b);
	b = new Button(levelTwoButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,300), Vec2(64*6,16*6));
	b->setFont(font_);
	b->setText("Level 2");
	b->setVisible(true);
	menu_buttons_.push_back(b);
	b = new Button(highScoreButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,150), Vec2(64*6,16*6));
	b->setFont(font_);
	b->setText("H1ghsc0re");
	b->setVisible(true);
	menu_buttons_.push_back(b);
	b = new Button(exitButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(1280-32*6-20,100), Vec2(32*6,8*6));
	b->setFont(font_);
	b->setText("3x1t");
	b->setVisible(true);
	menu_buttons_.push_back(b);

	//difficulty
	b = new Button(easyButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,400), Vec2(64*6,16*6));
	b->setFont(font_);
	b->setText("easy");
	difficulty_buttons_.push_back(b);

	b = new Button(normalButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,300), Vec2(64*6,16*6));
	b->setFont(font_);
	b->setText("normal");
	difficulty_buttons_.push_back(b);

	b = new Button(hardButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,200), Vec2(64*6,16*6));
	b->setFont(font_);
	b->setText("hard");
	difficulty_buttons_.push_back(b);

	b = new Button(backButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(1280-32*6-20,100), Vec2(32*6,8*6));
	b->setFont(font_);
	b->setText("back");
	difficulty_buttons_.push_back(b);
}

Startscreen::~Startscreen() {
	delete font_;
}

void Startscreen::tick(){


}

void Startscreen::draw() const {
	font_->setSize(3);
	bg_->draw(Vec2(0,0), Vec2(1280,720));

	if(drawMenuButtons_){
		for(Button* b : menu_buttons_){
			b->draw();
		}
	} else {
		for(Button* b : difficulty_buttons_){
			b->draw();
		}
	}

	font_->setSize(1.8);
	string by = "by Chris Brockhoff, Jonas Gerdes, Johann Luziv, Jonathan Wiemers";
	font_->draw_text(Vec2((1280-font_->compute_dimension(by).getX())/2, 10), by);
}

std::vector<Button*> Startscreen::getButtons(){
	vector<Button*> temp;
	temp.reserve(menu_buttons_.size()+difficulty_buttons_.size());
	temp.insert(temp.end(),menu_buttons_.begin(), menu_buttons_.end());
	temp.insert(temp.end(),difficulty_buttons_.begin(), difficulty_buttons_.end());
	return temp;
}

void Startscreen::setDrawMenuButtons(bool b){
	if(b){
		for(Button* b : menu_buttons_){
			b->setVisible(true);
		}
		for(Button* b : difficulty_buttons_){
			b->setVisible(false);
		}
	} else {
	for(Button* b : menu_buttons_){
			b->setVisible(false);
		}
		for(Button* b : difficulty_buttons_){
			b->setVisible(true);
		}

	}
	drawMenuButtons_ = b;
}

void Startscreen::setEnabled(bool enable){
	Screen::setEnabled(enable);
	for(Button* b : menu_buttons_){
		b->setVisible(enable);
	}
	for(Button* b : difficulty_buttons_){
		b->setVisible(enable);
	}
}



