/*
 * GameOverScreen.cpp
 *
 *  Created on: 21.06.2014
 *      Author: Chris
 */

#include "GameOverScreen.h"

using namespace std;

Gameoverscreen::Gameoverscreen(SpriteManager* spriteManager, bool enable) :
		Screen(spriteManager, enable),
		background_(spriteManager->getSprite("assets/graphics/menue.ppm")),
		font_(new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")){
		Button *b = new Button(playAgain, spriteManager->getSprite("assets/graphics/button.ppm"),Vec2((1280-64*6)/2.0,400), Vec2(64*6,16*8));
		b->setFont(font_);
		b->setText("Play again!");
		buttons_.push_back(b);

		Button *b = new Button(mainMenu, spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(1280-32*6-20,100), Vec2(32*6,8*6));
		b->setFont(font_);
		b->setText("Main menu");
		buttons_.push_back(b);
}

Gameoverscreen::~Gameoverscreen() {
	delete background_;
	delete font_;
	vector<Button*>::iterator iter = buttons_.begin();
	while(iter != buttons_.end()){
		delete (*iter++);
	}
}


void Gameoverscreen::tick() {

}

void Gameoverscreen::draw()const{
	for(Button* b : buttons_){
		b->draw();
	}
}

void Gameoverscreen::setEnabled(bool enable){
	Screen::setEnabled(enable);
	for(Button* b : buttons_){
		b->setVisible(enable);
	}
}

const vector<Button*>& Gameoverscreen::getButtons() const{
	return buttons_;
}
