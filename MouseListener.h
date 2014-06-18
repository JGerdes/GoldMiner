/*
 * MouseListener.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonas
 */

#ifndef MOUSELISTENER_H_
#define MOUSELISTENER_H_

#include "Vec2.h"

class MouseListener {
public:
	MouseListener();
	virtual ~MouseListener();
	virtual void onMouseMove(Vec2 screen_pos, Vec2 delta);
	virtual void onButtonUp(int button, Vec2 screen_pos);
	virtual void onButtonDown(int button , Vec2 screen_pos);
	virtual void onScroll(Vec2 offset);
};

#endif /* MOUSELISTENER_H_ */
