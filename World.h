#ifndef WORLD_H_
#define WORLD_H_

#include <vector>
#include "Block.h"
#include "Player.h"
#include "SpriteManager.h"
#include <string>

class Player;
class Block;

class World : public KeyListener{
public:
	World(SpriteManager* spriteManager);
	~World();
	void readMap(std::string fileName);
	void tick();
	void draw();
	void testBlockLife();
	void testCollision();

	void onKeyUp(int key);
	void onKeyDown(int key);

private:
	SpriteManager* sprite_manager_;
	Player* player_;
	std::vector<Block*>* map_;
	std::vector<Block*>* bg_map_;
};






#endif /* WORLD_H_ */
