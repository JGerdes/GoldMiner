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
#include <vector>
#include <string>

class Block : public Entity {
public:

	enum Type{
		dirt = 2,
		grass = 3,
		stone = 5,
		gold = 7,
	};

	Block(Type type, Vec2 position, Sprite* sprite);
	virtual ~Block();

	virtual void tick();

	void mine();
	const bool isDestroyed();


	const Type getType(){
		return type_;
	}

protected:
	Type type_;
	unsigned int damage_;
	unsigned int max_damage_;
	std::vector<std::string> paths_;
};

#endif /* BLOCK_H_ */
