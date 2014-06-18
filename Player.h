/*
 * Player.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonathan
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"
#include "InputManager.h"

class Player: public Entity {
public:
	Player(Sprite* sprite, Vec2 position, Vec2 dimension) :
			Entity(sprite, position, dimension) {

	}

	virtual ~Player();

	virtual void tick();

private:

};

#endif /* PLAYER_H_ */
