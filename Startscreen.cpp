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
		font_(new Font(spriteManager->getSprite("assets/graphics/font.ppm"),"assets/graphics/font.txt")){
	levelOneButton.setHandler(this);
	levelTwoButton.setHandler(this);
	font_->setColor(Color(1,1,1));
	font_->setSize(3);
}

Startscreen::~Startscreen() {
	delete font_;
}


void Startscreen::draw() {
	Entity::draw();
	levelOneButton.draw();
	font_->draw_text(Vec2((1280-64*5)/2.0,380), "Level 1");
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
	}
}
