
#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"
#include "../gui/io/InputManager.h"
#include "Block.h"

class Player: public Entity, public KeyListener {
public:
	Player(Sprite* sprite, Vec2 position, Vec2 dimension) :
			Entity(sprite, position, dimension),
			top_(nullptr),
			left_(nullptr),
			right_(nullptr),
			bottom_(nullptr){
		InputManager::getInstance().addKeyListener(this);

	}
	virtual ~Player();
	virtual void tick();

	void onKeyUp(int key);
	void onKeyDown(int key);
	void setNearestBlocks(Block* top, Block* left, Block* right, Block* bottom);
	void addToScore();
	void addToDestroyedBlocks();

	int getAllDestroyedBlocks() const;
	const unsigned int getScore() const;


private:
	unsigned int score_ = 0;
	unsigned int destroyed_blocks = 0;

	Block* top_, *left_, *right_, *bottom_;
};

#endif /* PLAYER_H_ */
