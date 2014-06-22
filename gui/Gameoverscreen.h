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
#include "Button.h"
#include <vector>

class Gameoverscreen : public Screen {
public:
	Gameoverscreen(SpriteManager* spriteManager, bool enable);
	~Gameoverscreen();

	virtual void tick();
	virtual void draw()const;
	virtual void setEnabled(bool enable);
	const std::vector<Button*>& getButtons() const;

	enum buttons{
		playAgain = 10,
		mainMenu = 11
	};

private:
	Sprite* background_;
	Font* font_;
	std::vector<Button*> buttons_;


};



#endif /* GAMEOVERSCREEN_H_ */
