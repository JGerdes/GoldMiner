/*
 * Startscreen.cpp
 *
 *  Created on: 20.06.2014
 *      Author: Chris
 */

#include <iostream>
#include <string>
#include "Startscreen.h"
#include "InputManager.h"
#include "Entity.h"


using namespace std;

Startscreen::Startscreen(SpriteManager* spriteManager, Vec2 position, Vec2 dimension) :
		Entity(spriteManager->getSprite("assets/graphics/menue.ppm"), position, dimension),
		startLevelOne(false),
		startLevelTwo(false),
		showHighscore(false),
		levelOneButton(Button(1, spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,400), Vec2(64*6,16*6))),
		levelTwoButton(Button(2, spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,300), Vec2(64*6,16*6))),
		highScoreButton(Button(3, spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,150), Vec2(64*6,16*6))),
		font_(new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")){
	levelOneButton.setHandler(this);
	levelTwoButton.setHandler(this);
	highScoreButton.setHandler(this);
	font_->setColor(Color(0,0,0));
	levelOneButton.setFont(font_);
	levelOneButton.setText("Level 1");
	levelTwoButton.setFont(font_);
	levelTwoButton.setText("Level 2");
	highScoreButton.setFont(font_);
	highScoreButton.setText("Highscore");
}

Startscreen::~Startscreen() {
	delete font_;
}


void Startscreen::draw() {
	Entity::draw();
	font_->setSize(3);
	levelOneButton.draw();
	levelTwoButton.draw();
	highScoreButton.draw();
	font_->setSize(1.8);
	string by = "by Chris Brockhoff, Jonas Gerdes, Johann Luziv, Jonathan Wiemers";
	font_->draw_text(Vec2((1280-font_->compute_dimension(by).getX())/2, 10), by);
}

bool Startscreen::isLevelOneStarting() const {
	return startLevelOne;
}

bool Startscreen::isLevelTwoStarting() const {
	return startLevelTwo;
}


bool Startscreen::isHighscoreKlicked() const{
	return showHighscore;
}

void Startscreen::setLevelOff() {
	startLevelOne = false;
	startLevelTwo = false;
	showHighscore = false;
}

void Startscreen::tick() {

}


void Startscreen::onButtonClick(unsigned int id){
	switch(id){
	case 1:
		startLevelOne = true;
		break;
	case 2:
		startLevelTwo = true;
		break;
	case 3:
		showHighscore = true;
	}
}
