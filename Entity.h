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
	Entity(Sprite sprite, Vec2 position, Vec2 dimension);
	virtual ~Entity();

	virtual void draw() const;
	virtual Entity& setDimension(Vec2 dim);
	virtual Entity& setPosition(Vec2 pos);
	virtual const Vec2& getPosition() const;
	virtual const Vec2& getDimension() const;
	virtual void tick();

private:
	Vec2 dimension_;
	Vec2 position_;
	Sprite sprite_;

};

#endif /* ENTITY_H_ */
