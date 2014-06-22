/*
 * Screen.h
 *
 *  Created on: 22.06.2014
 *      Author: Jonathan
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include "io/InputManager.h"
#include "SpriteManager.h"
class Screen {
public:

	Screen(SpriteManager* spriteManager) :
			spriteManager_(spriteManager) {
	}
	virtual ~Screen() {
	}
	virtual void tick() = 0;
	virtual void draw() const = 0;

private:
	SpriteManager* spriteManager_;
};

#endif /* SCREEN_H_ */
