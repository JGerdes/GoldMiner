/*
 * Startscreen.h
 *
 *  Created on: 20.06.2014
 *      Author: Chris
 */

#ifndef STARTSCREEN_H_
#define STARTSCREEN_H_

#include "../../gui/io/InputManager.h"
#include "../../objects/Entity.h"
#include "../Button.h"
#include "../SpriteManager.h"
#include "../Font.h"
#include "Screen.h"
#include <vector>

class Startscreen : public Screen{
public:
	enum button{
		levelOneButton = 0,
		levelTwoButton = 1,
		highScoreButton = 2,
		exitButton = 3,

		easyButton = 4,
		normalButton = 5,
		hardButton = 6,
		backButton = 7,

	};

	Startscreen(SpriteManager* spriteManager, bool enable, bool drawMenuButtons);
	~Startscreen();

	std::vector<Button*> getButtons();

	virtual void tick();
	virtual void draw() const;
	virtual void setEnabled(bool enable);

	void setDrawMenuButtons(bool b);



private:


	std::vector<Button*> menu_buttons_;
	std::vector<Button*> difficulty_buttons_;

	Font* font_;
	bool drawMenuButtons_;
	Sprite* bg_;
};


#endif /* STARTSCREEN_H_ */
