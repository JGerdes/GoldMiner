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
	 * @param score Die Anzahl der eingesammelten Goldbl�cke.
	 * @param destroyedBlocks Die Anzahl der zerst�rten Bl�cke
	 * @param maxBlocks Die anzahl der maxmimal zu zerst�renden Bl�cke - Wird durch die Schwirigkeitsstufe bestimmt.
	 */
	virtual void onLose(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks) = 0;
	virtual void onWin(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks) = 0;
};

#endif /* WORLDEVENTLISTENER_H_ */
