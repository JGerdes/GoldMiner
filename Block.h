/*
 * Block.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonas
 */

#ifndef BLOCK_H_
#define BLOCK_H_

#include "Vec2.h"
#include "MouseListener.h"
#include "Entity.h"

class Block : public Entity, MouseListener {
public:

	enum Type{
		dirt,
		gold
	};

	Block(Type type, Vec2 position, Sprite* sprite);
	virtual ~Block();
	virtual void tick();

	virtual void onMouseMove(Vec2 screen_pos, Vec2 delta);
	virtual void onButtonUp(int button, Vec2 screen_pos);
	virtual void onButtonDown(int button , Vec2 screen_pos);
	virtual void onScroll(Vec2 offset);

protected:
	Type type_;
};

#endif /* BLOCK_H_ */
