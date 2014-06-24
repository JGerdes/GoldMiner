/*
 * KeyListener.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonathan Wiemers, Jonas Gerdes
 */

#ifndef KEYLISTENER_H_
#define KEYLISTENER_H_

class KeyListener{
public:
	virtual ~KeyListener(){};
	virtual void onKeyUp(int key)=0;
	virtual void onKeyDown(int key)=0;
};

#endif /* KEYLISTENER_H_ */
