/*
 * Block.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonas
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "../Vec2.h"
#include "../gui/io/MouseListener.h"
#include "Entity.h"

class Block : public Entity {
public:

	enum Type{
		dirt,
		gold
	};

	Block(Type type, Vec2 position, Sprite* sprite, unsigned int maxdamage);
	virtual ~Block();
	virtual void tick();
	virtual void mine();
	virtual bool isDestroyed();


	Type getType(){
		return type_;
	}

protected:
	Type type_;
	unsigned int damage_;
	unsigned int max_damage_;
};

#endif /* BLOCK_H_ */
