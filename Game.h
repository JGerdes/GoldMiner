/*
 * Game.h
 *
 *  Created on: 06.06.2014
 *      Author: Jonas
 */

#ifndef GAME_H_
#define GAME_H_

#include <GLFW/glfw3.h>
#include "objects/World.h"
#include "objects/Player.h"
#include "gui/SpriteManager.h"
#include "gui/Highscore.h"
#include "gui/GameOverScreen.h"
#include "gui/Startscreen.h"
#include "gui/Worldscreen.h"
#include <vector>

class World;


class Game : public ButtonHandler{
public:
	enum screens{
		startscreen = 0,
		worldscreen = 1,
		gameoverscreen = 2,
		heighscorscreen = 3,
	};
	Game(double width, double height);
	virtual ~Game();
	virtual void onButtonClick(unsigned int id);
private:

	void init();
	void run();
	void render();

	GLFWwindow* window_;
	double window_width_;
	double window_height_;

	//TODO: only for test purposes!
	SpriteManager* sprite_manager_;

	Screen* currentScreen_;
	std::vector<Screen*> screens_;

};

#endif /* GAME_H_ */
