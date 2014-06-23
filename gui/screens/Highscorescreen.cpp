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
	font_(new Font(spriteManager->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")){

	Button* b = new Button(Startscreen::backButton,  spriteManager->getSprite("assets/graphics/button.ppm"),Vec2(1280-32*6-20,100), Vec2(32*6,8*6));
	b->setFont(font_);
	b->setText("back");
	buttons_.push_back(b);
}

Highscorescreen::~Highscorescreen() {
	// TODO Auto-generated destructor stub
}

