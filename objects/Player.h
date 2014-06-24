
#ifndef PLAYER_H_
#define PLAYER_H_

#include "Entity.h"
#include "../gui/io/InputManager.h"
#include "Block.h"


/**
 * @author Chris Brockhoff, Jonas Gerdes, Johann Luziv, Jonathan Wiemers
 *
 * Das Spielerobjekt von Goldminer.
 * Hat alle Informationen vom Spieler. Verarbeitet Benutzereingaben w�rend des Spiel.
 *
 */
class Player: public Entity, public KeyListener {
public:
	/**
	 * @param sprite
	 * @param position
	 * @param dimension
	 */
	Player(Sprite* sprite, Vec2 position, Vec2 dimension);
	virtual ~Player();
	virtual void tick();

	/**
	 * Implementierung des KeyListener
	 *
	 * @param key Die ID der Taste
	 */
	void onKeyUp(int key);
	void onKeyDown(int key);

	/**
	 * Setzt, falls es einen gibt, einen Pointer auf den n�chsten Block �ber,
	 * rechts und links neben und unter dem Playerobjekt.
	 *
	 * @param top Der Block �ber dem Spieler.
	 * @param left Der Block links neben dem Spieler.
	 * @param right Der Block rechts neben dem Spieler.
	 * @param bottom Der Block unter dem Spieler
	 */
	void setNearestBlocks(Block* top, Block* left, Block* right, Block* bottom);

	/**
	 *
	 */
	void addToScore();
	void addToDestroyedBlocks();

	int getAllDestroyedBlocks() const;
	const unsigned int getScore() const;


private:
	unsigned int score_ = 0;
	unsigned int destroyed_blocks = 0;

	Block* top_, *left_, *right_, *bottom_;
};

#endif /* PLAYER_H_ */
