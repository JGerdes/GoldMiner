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

	Screen(SpriteManager* spriteManager, bool enable) :
			spriteManager_(spriteManager),
			enabled_(enable){
	}
	virtual ~Screen() {
	}
	virtual void tick() = 0;
	virtual void draw() const = 0;

	bool isEnabled(){
		return enabled_;
	}

	virtual void setEnabled(bool enable){
		enabled_ = enable;
	}

private:
	SpriteManager* spriteManager_;
	bool enabled_;
};

#endif /* SCREEN_H_ */
