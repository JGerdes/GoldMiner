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
#include "gui/screens/GameOverScreen.h"
#include "gui/screens/Startscreen.h"
#include "gui/screens/Worldscreen.h"
#include "gui/screens/Highscorescreen.h"
#include "objects/WorldEventListener.h"
#include <vector>
#include <string>

class World;


class Game : public ButtonHandler, public WorldEventListener{
public:
	enum screens{
		startscreen = 0,
		worldscreen = 1,
		gameoverscreen = 2,
		highscorescreen = 3,
	};
	Game(double width, double height);
	virtual ~Game();
	virtual void onButtonClick(unsigned int id);
	virtual void onLose(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks);
	virtual void onWin(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks);
private:

	void init();
	void run();
	void render();
	void startWorld(unsigned int id);
	unsigned int computeScore(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks);

	GLFWwindow* window_;
	double window_width_;
	double window_height_;

	SpriteManager* sprite_manager_;

	Screen* currentScreen_;
	std::vector<Screen*> screens_;

	std::vector<std::string> level_files_;
	std::vector<Highscore*> scores_;
	unsigned int current_world_;
};

#endif /* GAME_H_ */
