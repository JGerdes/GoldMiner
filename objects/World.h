
#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "Block.h"
#include "Player.h"
#include "../gui/SpriteManager.h"
#include <string>
#include "../gui/Font.h"
#include "WorldEventListener.h"

class Player;
class Block;

/**
 * @author Chris Brockhoff, Jonas Gerdes, Johann Luziv, Jonathan Wiemers
 */
class World{
public:
	enum difficulty{
		EASY_GAME   = 30,
		NORMAL_GAME = 25,
		HARD_GAME   = 15,
	};


	World(SpriteManager* spriteManager, std::string map);
	~World();
	void readMap(std::string fileName);
	void tick();
	void draw() const;
	void testCollision();
	void onKeyUp(int key);
	void onKeyDown(int key);
	void setDifficulty(difficulty d);
	void setWorldEventListener(WorldEventListener* listener);

	bool getGameOver() const;
	const Player* getPlayer() const;

private:
	Block* createBlock(Block::Type, Sprite* sprite, int i, int rowCount);

	SpriteManager* sprite_manager_;
	Player* player_;
	std::vector<Block*>* map_;
	std::vector<Block*>* bg_map_;
	Font* font_;
	difficulty difficulty_;
	WorldEventListener* listener_;
	unsigned int gold_amount_;


};






#endif /* WORLD_H_ */
