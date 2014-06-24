#ifndef SCREEN_H_
#define SCREEN_H_

#include "../io/InputManager.h"
#include "../SpriteManager.h"
#include "../Font.h"
#include "../Button.h"
#include <vector>

/**
 * @author Jonathan Wiemers
 * Oberklasse für alle Screens. Kann deaktiviert werden, damit er nicht mehr
 * gezeichnet wird.
 */
class Screen {
public:

	/**
	 *
	 * @param spriteManager SpriteManager, über den Sprites geladen werden können
	 * @param font Schriftart, die standardmäßig genommen werden soll
	 * @param bg Hintergrundsprite
	 * @param enable Gibt an, ob Screen gezeichnet werden soll
	 */
	Screen(SpriteManager* spriteManager, Font* font, Sprite* bg, bool enable) :
			spriteManager_(spriteManager),
			enabled_(enable),
			font_(font),
			bg_(bg){
	}

	virtual ~Screen() {
		if(font_ != nullptr){
			delete font_;
		}
		if(bg_ != nullptr){
			delete bg_;
		}
		std::vector<Button*>::iterator iter = buttons_.begin();
		while(iter != buttons_.end()){
			delete (*iter++);
		}
	}
	virtual void tick() = 0;
	virtual void draw() const = 0;

	bool isEnabled() const{
		return enabled_;
	}

	virtual void setEnabled(bool enable){
		enabled_ = enable;
		for(Button* b : buttons_){
			b->setVisible(enable);
		}
	}

	/**
	 * Gibt Vektor mit allen Buttons zurück, damit Listener gesetzt werden können
	 * @return Vektor mit allen Buttons
	 */
	const std::vector<Button*>& getButtons() const{
		return buttons_;
	}

protected:
	SpriteManager* spriteManager_;
	bool enabled_;
	std::vector<Button*> buttons_;
	Font* font_;
	Sprite* bg_;
};

#endif /* SCREEN_H_ */
