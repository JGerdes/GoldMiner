/*
 * Startscreen.h
 *
 *  Created on: 20.06.2014
 *      Author: Chris
 */

#ifndef STARTSCREEN_H_
#define STARTSCREEN_H_

#include "InputManager.h"
#include "Entity.h"
#include "Button.h"
#include "SpriteManager.h"
#include "Font.h"

class Startscreen : public Entity, public ButtonHandler{
public:
	Startscreen(SpriteManager* spriteManager, Vec2 position, Vec2 dimension);
	~Startscreen();
	void tick();
	void draw();
	bool isLevelOneStarting()const;
	bool isLevelTwoStarting()const;
	bool isHighscoreKlicked() const;
	void setLevelOff();
	virtual void onButtonClick(unsigned int id);


private:
	bool startLevelOne;
	bool startLevelTwo;
	bool showHighscore;
	Button levelOneButton;
	Button levelTwoButton;
	Font* font_;
};


#endif /* STARTSCREEN_H_ */
