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

/**
 * @author Chris Brockhoff, Jonas Gerdes, Jonathan Wiemers
 *
 * Screen der angezeigt wird, wenn der Spieler verloren oder gewonnen hat.
 * Neben der Punktzahlt zeigt er je einen Button zum Hauptmenü und zur
 * Schwierigkeitsauswahl an
 */
class Gameoverscreen : public Screen {
public:
	enum buttons{
			playAgain = 10,
			mainMenu = 11
		};

	/**
	 *
	 * @param spriteManager
	 * @param enable
	 * Siehe Screen.h
	 */
	Gameoverscreen(SpriteManager* spriteManager, bool enable);
	~Gameoverscreen();


	virtual void tick();
	virtual void draw()const;
	void setText(std::string text);
	void setScore(int score);

private:
	std::string text_;
	int score_;


};



#endif /* GAMEOVERSCREEN_H_ */
