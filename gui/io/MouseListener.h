
#ifndef MOUSELISTENER_H_
#define MOUSELISTENER_H_

#include "../../Vec2.h"

/**
 * @author Jonas Gerdes
 *
 * Interface zum Abhören von Mausevents. Muss implementiert werden,
 * um sich beim InputManager als MouseListener registieren zu können.
 */
class MouseListener {
public:
	MouseListener(){};
	virtual ~MouseListener(){}

	/**
	 * Wird aufgerufen, wenn die Mausbewegt wird
	 * @param screen_pos Position der Maus auf dem Screen. Der Nullpunkt liegt
	 * unten rechts
	 * @param delta	Distanz (in beide Richtungen), die die Maus seit dem letzten Aufruf dieser Methode zurückgelegt hat
	 */
	virtual void onMouseMove(Vec2 screen_pos, Vec2 delta)=0;

	/**
	 * Wird aufgerufen, wenn eine Maustaste losgelassen wird
	 * @param key Eideutiger Tastencode für die losgelassene Taste (GLFW Konstante)
	 */
	virtual void onButtonUp(int button, Vec2 screen_pos)=0;

	/**
	 * Wird aufgerufen, wenn eine Maustaste gedrückt wird
	 * Auch wenn die Taste festgehalten wird, diese Methode wird nur einmal aufgerufen
	 * @param key Eideutiger Tastencode für die gedrückte Taste (GLFW Konstante)
	 * @return true, wenn das Event abgefangen wurde. Dadurch wird im InputManager kein weiterer
	 * Listener mit diesem Event benachrichtigt
	 */
	virtual bool onButtonDown(int button , Vec2 screen_pos)=0;

	/**
	 * Wird aufgerufen, wenn das Mausrad gescrollt wurde
	 * @param offset Wert, wie weit das Mausrad gescrollt wurde
	 */
	virtual void onScroll(Vec2 offset)=0;
};

#endif /* MOUSELISTENER_H_ */
