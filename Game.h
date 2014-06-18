/*
 * Game.h
 *
 *  Created on: 06.06.2014
 *      Author: Jonas
 */

#ifndef GAME_H_
#define GAME_H_

#include <GLFW/glfw3.h>
#include "Player.h"
#include "SpriteManager.h"


class Game {
public:
	Game(double width, double height);
	virtual ~Game();

private:
	GLFWwindow* window_;
	double window_width_;
	double window_height_;


	void init();
	void run();

	void render();

	//TODO: only for test purposes!
	SpriteManager sprite_manager_;


};

#endif /* GAME_H_ */
