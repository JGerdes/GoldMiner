/*
 * Worldscreen.h
 *
 *  Created on: 22.06.2014
 *      Author: Jonathan
 */

#ifndef WORLDSCREEN_H_
#define WORLDSCREEN_H_

#include "Screen.h"
#include "../objects/World.h"

class Worldscreen: public Screen {
public:
	Worldscreen(SpriteManager* spriteManager);
	virtual ~Worldscreen();
	virtual void tick();
	virtual void draw() const ;

	void setLevel(World* world);


private:
	World* world_;
};

#endif /* WORLDSCREEN_H_ */
