#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "Block.h"
#include "Player.h"
#include "SpriteManager.h"
#include <string>

class Player;
class Block;

class World {
public:
	World(SpriteManager* spriteManager);
	~World();
	void readMap(std::string fileName);
	void tick();
	void draw();
	void testBlockLife();
	void testCollision();
private:
	SpriteManager* sprite_manager_;
	Player* player;
	std::vector<Block*>* map;
};






#endif /* WORLD_H_ */
