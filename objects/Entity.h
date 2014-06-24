#ifndef ENTITY_H_
#define ENTITY_H_

#include "../Vec2.h"
#include "../gui/Sprite.h"

/**
 * @author Jonathan Wiemers
 *
 *	Abstrakt. Alle in der World platzierbaren Objekte erben von der Klasse Entity.
 *	Sie enthält Position und Größe sowie das Sprite,
 *	welches in der Methode draw des Entities an der entsprechenden Position gezeichnet wird.
 *
 */
class Entity {
public:
	Entity(Sprite* sprite, Vec2 position, Vec2 dimension);
	virtual ~Entity();

	/**
	 * Ruft die draw Methode vom sprite_ auf.
	 */
	virtual void draw() const;

	/**
	 * Muss von der erbenden Klasse implementiert werden.
	 */
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
