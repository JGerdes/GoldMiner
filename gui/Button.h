#ifndef BUTTON_H_
#define BUTTON_H_

#include <string>
#include "../objects/Entity.h"
#include "io/MouseListener.h"
#include "Sprite.h"
#include "../Vec2.h"
#include "Font.h"

/**
 * @author Jonas Gerdes
 *
 * Interface, das implementiert werden muss, um sich beim Button als Listener zu
 * registrieren.
 *
 */
class ButtonHandler{
public:
	ButtonHandler(){}
	virtual ~ButtonHandler(){};

	/**
	 *	Wird aufgerufen sobald ein Button, für den sich vorher registriert wurde,
	 *	geklickt wurde
	 * @param id des Buttons
	 */
	virtual void onButtonClick(unsigned int id) = 0;
};


/**
 * @author Jonas Gerdes, Jonathan Wiemers
 *
 * Gibt beim Klicken dem Listener Bescheid.
 * Kann unsichtbar gemacht werden, damit Klicken nicht abgefangen und
 * der Button nicht gezeichnet wird.
 * Besitzt eine Id, damit Objekte, die Listener für mehrere Buttons sind,
 * zuordnen können, vom welchem Button die Events stammen.
 * Sprites für den Button sind in der Mitte geteilt. Wenn die Maus auserhalb
 * des Buttons liegt, wird die linke Hälfte gezeichnet, sonst die rechte.
 */
class Button : public Entity, public MouseListener{
public:
	Button(unsigned int id, Sprite* sprite, Vec2 position, Vec2 dimension);
	virtual ~Button();
	virtual void onMouseMove(Vec2 screen_pos, Vec2 delta);
	virtual void onButtonUp(int button, Vec2 screen_pos);
	/**
	 * Ruft Listener aus, wenn Button sichtbar ist
	 * @param button
	 * @param screen_pos
	 * @return true wenn in den Button geklickt wurde und dieser sichtbar ist,
	 * sonst false
	 */
	virtual bool onButtonDown(int button , Vec2 screen_pos);
	virtual void onScroll(Vec2 offset);

	/**
	 * Listener setzen (stets nur einer gleichzeitig)
	 * @param handler Neuer Klicklistener (ersetzt den alten)
	 */
	virtual void setHandler(ButtonHandler* handler);
	virtual void setFont(Font* font);

	/**
	 * Text setzen, der auf den Button angezeigt werden soll. Standard
	 * ist "Button" gefolgt von der im Konstruktor angegebenen Id
	 * @param text neuer Text
	 */
	virtual void setText(std::string text);

	/**
	 * Zeichnet je nach Mausposition die linke oder rechte Hälfte der Sprite.
	 * Zeichnet Text mittig auf den Button, wenn Font gesetzt ist (kein nullptr)
	 */
	virtual void draw();
	virtual void tick(){}

	void setVisible(bool b);
private:

	unsigned int id_;
	bool isHovered_;
	ButtonHandler* handler_;
	Font* font_;
	std::string text_;
	bool visible_;
};

#endif /* BUTTON_H_ */
