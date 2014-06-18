#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "Block.h"
#include "Player.h"
#include "SpriteManager.h"

class Player;
class Block;

class World {
public:
	World(SpriteManager spriteManager);
	~World();
	std::vector<Block*> createMap();
	void update();
	void draw();
	void testBlockLife();
	void testCollision();
private:
	SpriteManager sprite_manager_;
	Player* player;
	std::vector<Block*> map;
	bool collisonRight, collisionLeft, collisionDown, collisionUp;
};






#endif /* WORLD_H_ */
