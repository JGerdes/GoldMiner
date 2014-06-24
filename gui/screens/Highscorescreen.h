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
#include <vector>
#include <string>

class Highscorescreen: public Screen {
public:
	enum{
		backButton = 12
	};

	Highscorescreen(SpriteManager* spriteManager, bool enable);
	virtual ~Highscorescreen();

	virtual void tick();
	virtual void draw() const;

	void setHighscores(std::vector<unsigned int> level_1, std::vector<unsigned int> level_2);


private:

	std::vector<std::string> level_1_, level_2_;
};

#endif /* HIGHSCORESCREEN_H_ */
