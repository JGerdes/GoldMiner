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
#include "../Highscore.h"

class Highscorescreen: public Screen {
public:
	Highscorescreen(SpriteManager* spriteManager, bool enable);
	virtual ~Highscorescreen();

	virtual void tick();
	virtual void draw() const;

	virtual void setEnabled(bool enable);

	void setHighscore(Highscore* h);


private:

	std::vector<Button*> buttons_;
	Font* font_;
	Sprite* bg_;
	Highscore* highscore_;


};

#endif /* HIGHSCORESCREEN_H_ */
