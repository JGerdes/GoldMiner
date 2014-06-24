#ifndef ENTITY_H_
#define ENTITY_H_

#include "../Vec2.h"
#include "../gui/Sprite.h"

class Entity {
public:
	Entity(Sprite* sprite, Vec2 position, Vec2 dimension);
	virtual ~Entity();

	virtual void draw() const;
	virtual void tick() = 0;

	virtual Entity& setDimension(Vec2 dim);
	virtual Entity& setPosition(Vec2 pos);

	virtual Vec2 getPosition() const;
	virtual Vec2 getDestination() const;
	virtual const Vec2& getDimension() const;



protected:
	Vec2 dimension_;
	Vec2 position_;
	Vec2 destination_;
	Sprite* sprite_;

};

#endif /* ENTITY_H_ */
