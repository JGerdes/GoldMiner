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
	WorldEventListener(){}
	virtual ~WorldEventListener(){}

	virtual void onLose(unsigned int score, unsigned int destroyedBlocks) = 0;
	virtual void onWin(unsigned int score, unsigned int destroyedBlocks) = 0;
};

#endif /* WORLDEVENTLISTENER_H_ */
