/*
 * Worldscreen.h
 *
 *  Created on: 22.06.2014
 *      Author: Jonathan
 */

#ifndef WORLDSCREEN_H_
#define WORLDSCREEN_H_

#include "Screen.h"
#include "../../objects/World.h"

/**
 * @author Jonathan Wiemers
 *
 * Zeigt eine Spielwelt an. Leitet Aufruf von tick und draw an die Welt weiter
 */
class Worldscreen: public Screen {
public:
	Worldscreen(SpriteManager* spriteManager, bool enable);
	virtual ~Worldscreen();
	virtual void tick();
	virtual void draw() const ;

	/**
	 * Setzen der zu spielenden Welt
	 * @param world
	 */
	void setWorld(World* world);

	World* getWorld();


private:
	World* world_;
};

#endif /* WORLDSCREEN_H_ */
