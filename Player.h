/*
void Player::onKeyDown(int key){

}
 * Player.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonathan
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"
#include "InputManager.h"
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
	void onKeyUp(int key);
	void onKeyDown(int key);

	virtual ~Player();
	virtual void tick();

	void setNearestBlocks(Block* top, Block* left, Block* right, Block* bottom);

	const int& getScore();
	void addToScore();
private:
	unsigned int score = 0;
	Block* top_, *left_, *right_, *bottom_;
};

#endif /* PLAYER_H_ */
