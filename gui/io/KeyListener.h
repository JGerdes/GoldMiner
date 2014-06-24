#ifndef KEYLISTENER_H_
#define KEYLISTENER_H_

/**
 * @author Jonas Gerdes
 *
 * Interface zum Abh�ren von Tastaturevents. Muss implementiert werden,
 * um sich beim InputManager als KeyListener registieren zu k�nnen.
 */
class KeyListener{
public:
	virtual ~KeyListener(){};

	/**
	 * Abstrakt. Wird aufgerufen, wenn eine Taste losgelassen wird
	 * @param key Eideutiger Tastencode f�r die losgelassene Taste (GLFW Konstante)
	 */
	virtual void onKeyUp(int key)=0;

	/**
	 * Abstrakt. Wird aufgerufen, wenn eine Taste gedr�ckt wird
	 * Auch wenn die Taste festgehalten wird, diese Methode wird nur einmal aufgerufen
	 * @param key Eideutiger Tastencode f�r die gedr�ckte Taste (GLFW Konstante)
	 */
	virtual void onKeyDown(int key)=0;
};

#endif /* KEYLISTENER_H_ */
