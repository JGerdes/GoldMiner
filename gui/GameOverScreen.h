/*
 * GameOverScreen.h
 *
 *  Created on: 21.06.2014
 *      Author: Chris
 */

#ifndef GAMEOVERSCREEN_H_
#define GAMEOVERSCREEN_H_

#include "io/InputManager.h"
#include "../objects/Entity.h"

class GameOverScreen : public MouseListener, public Entity {
public:
	GameOverScreen(Sprite* sprite, Vec2 position, Vec2 dimension);
	~GameOverScreen();
	void onButtonDown(int button , Vec2 screen_pos);
	void onMouseMove(Vec2 screen_pos, Vec2 delta);
	void onButtonUp(int button, Vec2 screen_pos);
	void onScroll(Vec2 offset);
	void tick();
	bool getIsGameOver();
	void setGameOver(bool gameOver);
private:
	bool isGameOver;
};



#endif /* GAMEOVERSCREEN_H_ */
