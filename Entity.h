/*
 * Entity.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonathan
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Vec2.h"
#include "Sprite.h"

class Entity {
public:
	Entity(Sprite sprite, Vec2 position, Vec2 dimension) :
			dimension_(dimension), position_(position), sprite_(sprite) {
	}

	virtual ~Entity();

	virtual Entity& draw() const {
		sprite_.draw(position_, dimension_);
		return *this;
	}

	virtual Entity& setDimension(Vec2 dim){
		this->dimension_ = dim;
		return *this;
	}

	virtual Entity& setPosition(Vec2 pos){
		this->position_ = pos;
		return *this;
	}

private:
	Vec2 dimension_;
	Vec2 position_;
	Sprite sprite_;

};

#endif /* ENTITY_H_ */
