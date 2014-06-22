/*
 * MouseListener.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonas
 */

#ifndef MOUSELISTENER_H_
#define MOUSELISTENER_H_

#include "../../Vec2.h"

class MouseListener {
public:
	MouseListener(){};
	virtual ~MouseListener(){}
	virtual void onMouseMove(Vec2 screen_pos, Vec2 delta)=0;
	virtual void onButtonUp(int button, Vec2 screen_pos)=0;
	virtual bool onButtonDown(int button , Vec2 screen_pos)=0;
	virtual void onScroll(Vec2 offset)=0;
};

#endif /* MOUSELISTENER_H_ */
