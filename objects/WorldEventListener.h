#ifndef WORLDEVENTLISTENER_H_
#define WORLDEVENTLISTENER_H_

class WorldEventListener {
public:
	WorldEventListener(){}
	virtual ~WorldEventListener(){}

	virtual void onLose(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks) = 0;
	virtual void onWin(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks) = 0;
};

#endif /* WORLDEVENTLISTENER_H_ */
