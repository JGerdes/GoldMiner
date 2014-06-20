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

class Startscreen : public MouseListener, public Entity{
public:
	Startscreen(Sprite* sprite, Vec2 position, Vec2 dimension);
	~Startscreen();
	void tick();
	void drawBg();
	void onButtonDown(int button , Vec2 screen_pos);
	void onMouseMove(Vec2 screen_pos, Vec2 delta);
	void onButtonUp(int button, Vec2 screen_pos);
	void onScroll(Vec2 offset);
	bool isLevelOneStarting()const;
	bool isLevelTwoStarting()const;
	bool isHighscoreStarting()const;

private:
	bool startLevelOne;
	bool startLevelTwo;
	bool startHighscore;
};


#endif /* STARTSCREEN_H_ */
