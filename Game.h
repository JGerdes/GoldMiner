/*
 * Game.h
 *
 *  Created on: 06.06.2014
 *      Author: Jonas
 */

#ifndef GAME_H_
#define GAME_H_

#include <GLFW/glfw3.h>
#include "objects/Player.h"
#include "gui/SpriteManager.h"
#include "objects/World.h"
#include "gui/Startscreen.h"
#include "gui/Highscore.h"
#include "gui/GameOverScreen.h"

class World;


class Game : public KeyListener{
public:
	Game(double width, double height);
	virtual ~Game();
	void onKeyUp(int key);
	void onKeyDown(int key);

private:

	void init();
	void run();
	void render();

	GLFWwindow* window_;
	double window_width_;
	double window_height_;

	//TODO: only for test purposes!
	SpriteManager* sprite_manager_;
	World* world_;
	World* world1_;
	Highscore *highscore;
	Startscreen* startscreen_;
	enum Gamestate {menue, runningLevelOne, runningLevelTwo, gameover} gamestate;
	bool exit;
	GameOverScreen* gameoverscreen_;

};

#endif /* GAME_H_ */
