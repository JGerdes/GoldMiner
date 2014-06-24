#ifndef STARTSCREEN_H_
#define STARTSCREEN_H_

#include "../../gui/io/InputManager.h"
#include "../../objects/Entity.h"
#include "../Button.h"
#include "../SpriteManager.h"
#include "../Font.h"
#include "Screen.h"
#include <vector>


/**
 * @author Chris Brockhoff, Jonas Gerdes, Jonathan Wiemers
 *
 * Hauptscreen des Spiels, zeigt Buttons zu anderen Screens und zum Beedenen an
 * Besitzt Buttons für das Menü und für die Schwierigkeitsauswahl, die abwechselnd
 * angezeigt werden können
 */
class Startscreen : public Screen{
public:
	enum button{
		levelOneButton = 0,
		levelTwoButton = 1,
		highScoreButton = 2,
		exitButton = 3,

		easyButton = 4,
		normalButton = 5,
		hardButton = 6,
		backButton = 7,

	};

	/**
	 *
	 * @param spriteManager
	 * @param enable
	 * @param drawMenuButtons Wenn true, werden die Button für das Menü angezeigt, sonst jene
	 * für die Schwierigkeitsauswahl
	 * siese Screen.h
	 */
	Startscreen(SpriteManager* spriteManager, bool enable, bool drawMenuButtons);
	~Startscreen();

	std::vector<Button*> getButtons();

	virtual void tick();
	virtual void draw() const;
	virtual void setEnabled(bool enable);

	/**
	 * Umschalten zwischen Menübutton und Schwierigkeitsauswahl
	 * @param b Wenn wahr, werden Menübuttons angezeigt, sonst jene
	 * für die Schwierigkeitsauswahl
	 */
	void setDrawMenuButtons(bool b);



private:
	std::vector<Button*> menu_buttons_;
	std::vector<Button*> difficulty_buttons_;

	bool draw_menu_buttons_;
};


#endif /* STARTSCREEN_H_ */
