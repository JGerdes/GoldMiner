#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "Block.h"
#include "Player.h"
#include "../gui/SpriteManager.h"
#include <string>
#include "../gui/Font.h"

class Player;
class Block;

class World{
public:
	World(SpriteManager* spriteManager, std::string map);
	~World();
	void readMap(std::string fileName);
	void tick();
	void draw();
	void testCollision();
	Player* getPlayer() const;
	void onKeyUp(int key);
	void onKeyDown(int key);
	void resetGame();
	bool getGameOver() const;

	bool getGameOver(){
		return gameOver;
	}
	void setGameOver(bool gameOver_){
		gameOver = gameOver_;
	}
	const int FREE_GAME	  = 1000;
	const int EASY_GAME   = 30;
	const int NORMAL_GAME = 25;
	const int HARD_GAME   = 15;

private:
	bool gameOver = false;
	SpriteManager* sprite_manager_;
	Player* player_;
	std::vector<Block*>* map_;
	std::vector<Block*>* bg_map_;
	Font* font_;
};






#endif /* WORLD_H_ */
