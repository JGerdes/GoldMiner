/*
 * GameOverScreen.h
 *
 *  Created on: 21.06.2014
 *      Author: Chris
 */

#ifndef GAMEOVERSCREEN_H_
#define GAMEOVERSCREEN_H_

#include "../io/InputManager.h"
#include "Screen.h"
#include "../Button.h"
#include <vector>
#include <string>

class Gameoverscreen : public Screen {
public:
	enum buttons{
			playAgain = 10,
			mainMenu = 11
		};

	Gameoverscreen(SpriteManager* spriteManager, bool enable);
	~Gameoverscreen();

	virtual void tick();
	virtual void draw()const;
	virtual void setEnabled(bool enable);
	std::vector<Button*>& getButtons();
	void setText(std::string text);
	void setScore(int score);

private:
	Sprite* bg_;
	Font* font_;
	std::vector<Button*> buttons_;
	std::string text_;
	int score_;


};



#endif /* GAMEOVERSCREEN_H_ */
