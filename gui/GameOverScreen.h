/*
 * GameOverScreen.h
 *
 *  Created on: 21.06.2014
 *      Author: Chris
 */

#ifndef GAMEOVERSCREEN_H_
#define GAMEOVERSCREEN_H_

#include "io/InputManager.h"
#include "Screen.h"

class GameOverScreen : public Screen {
public:
	GameOverScreen(SpriteManager* spriteManager, bool enable);
	~GameOverScreen();

	virtual void tick();
	virtual void draw()const;

private:

};



#endif /* GAMEOVERSCREEN_H_ */
