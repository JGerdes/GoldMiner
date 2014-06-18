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
			canJump_(true),
			canMoveLeft_(true),
			canMoveRight_(true),
			canFall_(true){
		InputManager::getInstance().addKeyListener(this);

	}
	void onKeyUp(int key);
	void onKeyDown(int key);

	virtual ~Player();
	virtual void tick();

	void setMoveables(bool canJump, bool canMoveLeft, bool canMoveRight, bool canFall);

private:

	bool canJump_, canMoveLeft_, canMoveRight_, canFall_;
};

#endif /* PLAYER_H_ */
