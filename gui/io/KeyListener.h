#ifndef KEYLISTENER_H_
#define KEYLISTENER_H_

/**
 * @author Jonas Gerdes
 *
 * Interface zum Abhören von Tastaturevents. Muss implementiert werden,
 * um sich beim InputManager als KeyListener registieren zu können.
 */
class KeyListener{
public:
	virtual ~KeyListener(){};

	/**
	 * Abstrakt. Wird aufgerufen, wenn eine Taste losgelassen wird
	 * @param key Eideutiger Tastencode für die losgelassene Taste (GLFW Konstante)
	 */
	virtual void onKeyUp(int key)=0;

	/**
	 * Abstrakt. Wird aufgerufen, wenn eine Taste gedrückt wird
	 * Auch wenn die Taste festgehalten wird, diese Methode wird nur einmal aufgerufen
	 * @param key Eideutiger Tastencode für die gedrückte Taste (GLFW Konstante)
	 */
	virtual void onKeyDown(int key)=0;
};

#endif /* KEYLISTENER_H_ */
