#ifndef WORLDEVENTLISTENER_H_
#define WORLDEVENTLISTENER_H_

/**
 * @author Jonathan Wiemers
 *
 * Abstrakte Klasse.
 * Die Erbene Klasse muss onLose und onWin implementieren.
 *
 */
class WorldEventListener {
public:
	WorldEventListener(){}
	virtual ~WorldEventListener(){}

	/**
	 * @param score Die Anzahl der eingesammelten Goldblöcke.
	 * @param destroyedBlocks Die Anzahl der zerstörten Blöcke
	 * @param maxBlocks Die anzahl der maxmimal zu zerstörenden Blöcke - Wird durch die Schwirigkeitsstufe bestimmt.
	 */
	virtual void onLose(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks) = 0;
	virtual void onWin(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks) = 0;
};

#endif /* WORLDEVENTLISTENER_H_ */
