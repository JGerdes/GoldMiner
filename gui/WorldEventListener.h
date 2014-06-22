/*
 * WorldEventListener.h
 *
 *  Created on: 22.06.2014
 *      Author: Jonathan
 */

#ifndef WORLDEVENTLISTENER_H_
#define WORLDEVENTLISTENER_H_

class WorldEventListener {
public:
	WorldEventListener();
	virtual ~WorldEventListener();

	void onGameOver() = 0;

	//O.O DAT WORLD EVENT
	void onZuckerBergFallDown() = 0;
};

#endif /* WORLDEVENTLISTENER_H_ */
