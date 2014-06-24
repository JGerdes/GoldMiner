#ifndef HIGHSCORESCREEN_H_
#define HIGHSCORESCREEN_H_

#include "Screen.h"
#include "../Button.h"
#include "../Font.h"
#include "../Highscore.h"
#include <vector>
#include <string>

/**
 * @author Chris Brockhoff, Jonas Gerdes, Jonathan Wiemers
 *
 * Zeigt den Highscore für die zwei Level an
 */
class Highscorescreen: public Screen {
public:
	enum{
		backButton = 12
	};


	Highscorescreen(SpriteManager* spriteManager, bool enable);
	virtual ~Highscorescreen();

	virtual void tick();
	virtual void draw() const;

	/**
	 * Setzt bzw. aktualisiert die Highscores
	 * @param level_1 Vector mit Scores des Level 1
	 * @param level_2 Vector mit Scores des Level 2
	 */
	void setHighscores(const std::vector<unsigned int>& level_1, const std::vector<unsigned int>& level_2);


private:

	std::vector<std::string> level_1_, level_2_;
};

#endif /* HIGHSCORESCREEN_H_ */
