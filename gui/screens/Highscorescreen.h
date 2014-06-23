/*
 * Highscorescreen.h
 *
 *  Created on: 23.06.2014
 *      Author: Jonathan
 */

#ifndef HIGHSCORESCREEN_H_
#define HIGHSCORESCREEN_H_

#include "Screen.h"
#include "../Button.h"
#include "../Font.h"

class Highscorescreen: public Screen {
public:
	Highscorescreen(SpriteManager* spriteManager, bool enable);
	virtual ~Highscorescreen();

	virtual void tick();
	virtual void draw() const;

	virtual void setEnabled(bool enable);
private:
	Sprite* bg_;
	std::vector<Button*> buttons_;
	Font* font_;

};

#endif /* HIGHSCORESCREEN_H_ */
