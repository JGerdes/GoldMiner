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

Startscreen::Startscreen(SpriteManager* spriteManager, bool enable) :
		Screen(spriteManager, enable),
		font_(new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")){

	bg_ = spriteManager->getSprite("assets/graphics/menue.ppm");

	font_->setColor(Color(0,0,0));
	Button* b = new Button(levelOneButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,400), Vec2(64*6,16*6));
	b->setFont(font_);
	b->setText("Level 1");
	buttons_.push_back(b);
	b = new Button(levelTwoButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,300), Vec2(64*6,16*6));
	b->setFont(font_);
	b->setText("Level 2");
	buttons_.push_back(b);
	b = new Button(highScoreButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,150), Vec2(64*6,16*6));
	b->setFont(font_);
	b->setText("H1ghsc0re");
	buttons_.push_back(b);
	b = new Button(exitButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(1280-32*6-20,100), Vec2(32*6,8*6));
	b->setFont(font_);
	b->setText("3x1t");
	buttons_.push_back(b);
	cout << "startscreen created" << endl;
}

Startscreen::~Startscreen() {
	delete font_;
}

void Startscreen::tick(){


}

void Startscreen::draw() const {
	font_->setSize(3);
	bg_->draw(Vec2(0,0), Vec2(1280,720));

	for(Button* b : buttons_){
		b->draw();
	}

	font_->setSize(1.8);
	string by = "by Chris Brockhoff, Jonas Gerdes, Johann Luziv, Jonathan Wiemers";
	font_->draw_text(Vec2((1280-font_->compute_dimension(by).getX())/2, 10), by);
}

Button* Startscreen::getButton(int id){
	return buttons_.at(id);
}

