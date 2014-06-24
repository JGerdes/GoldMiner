#ifndef BLOCK_H_
#define BLOCK_H_

#include "../Vec2.h"
#include "../gui/io/MouseListener.h"
#include "Entity.h"
#include <vector>
#include <string>

/**
 * @author Jonas Gerdes, Jonathan Wiemers
 *
 * Die Welt, in der sich der Spieler bewegen kann, besteht aus Objekten der Klasse Block.
 * Jeder Block hat einen Typ der durch ein Enum abgebildet wird.
 *
 */
class Block : public Entity {
public:

	/**
	 * Enmu das den Zusammenhang zwischen dem Tüp des Blocks und dem Schaden den der Block erleiden kann her.
	 */
	enum Type{
		dirt = 2,
		grass = 3,
		stone = 5,
		gold = 7,
	};

	Block(Type type, Vec2 position, Sprite* sprite);
	virtual ~Block();


	virtual void tick();

	/**
	 * Wird aufgerunfen um dem aktuellen Objekt +1 Schaden zuzufügen.
	 */
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
