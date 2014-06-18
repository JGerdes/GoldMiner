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

class Player: public Entity, public KeyListener {
public:
	Player(Sprite* sprite, Vec2 position, Vec2 dimension) :
			Entity(sprite, position, dimension),
			canJump(true),
			canMoveLeft(true),
			canMoveRight(true),
			canFall(true){

	}
	void onKeyUp(int key);
	void onKeyDown(int key);

	virtual ~Player();

	virtual void tick();

private:

	bool canJump, canMoveLeft, canMoveRight, canFall;
};

#endif /* PLAYER_H_ */
