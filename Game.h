#ifndef GAME_H_
#define GAME_H_

#include <GLFW/glfw3.h>
#include "objects/World.h"
#include "objects/Player.h"
#include "gui/SpriteManager.h"
#include "gui/Highscore.h"
#include "gui/screens/GameOverScreen.h"
#include "gui/screens/Startscreen.h"
#include "gui/screens/Worldscreen.h"
#include "gui/screens/Highscorescreen.h"
#include "objects/WorldEventListener.h"
#include <vector>
#include <string>

class World;

/**
 * @author Jonas Gerdes, Jonathan Wiemers
 *
 * Speichert die Festergröße, Initzialisert GLFW, Verwaltet die anzuzeigenen Screens.
 *
 *
 */
class Game : public ButtonHandler, public WorldEventListener{
public:

	/**
	 * Enum das den Zusammenhang zwischen einem bestimmten Screen und der Position im screens_ vector herstellt.
	 */
	enum screens{
		startscreen = 0,
		worldscreen = 1,
		gameoverscreen = 2,
		highscorescreen = 3,
	};

	/**
	 * Fenster größe
	 */
	static double window_width;
	static double window_height;

	/**
	 *
	 * @param width Breite des Fensters
	 * @param height Höhe des Fensters
	 */
	Game(double width, double height);
	~Game();
	/**
	 * Implementierung des ButtonHandler´s.
	 * @param id Die Button ID.
	 */
	virtual void onButtonClick(unsigned int id);

	/**
	 * Implementierung des WorldEventListeners
	 * @param score Die Anzahl der eingesammelten Goldblöcke.
	 * @param destroyedBlocks Die Anzahl der zerstörten Blöcke
	 * @param maxBlocks Die anzahl der maxmimal zu zerstörenden Blöcke - Wird durch die Schwirigkeitsstufe bestimmt.
	 */
	virtual void onLose(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks);
	virtual void onWin(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks);
private:

	/**
	 * Initialisiert OpenGL, Registreiert User Callbacks bei GLFW,
	 * Läd die Highscores und Inizialisiert alle Screens.
	 */
	void init();

	/**
	 * Läuft so lange das Spiel nicht beendet wurde.
	 * Ruft die tick Funktion des aktuellen Screens auf.
	 * Anschließend wird die private Methode render aufgerufen.
	 */
	void run();

	/**
	 * Zeichnet den aktuellen Screen.
	 */
	void render() const;

	/**
	 * Inizialisiert eine World im Worldscreen
	 * @param id Die Position der Level Datei im level_files_ vector.
	 */
	void startWorld(unsigned int id);

	/**
	 * Berechnet die Punktzahl die der Spieler im Spiel geschaft hat.
	 *
	 * @param score Die Anzahl der eingesammelten Goldblöcke.
	 * @param destroyedBlocks Die Anzahl der zerstörten Blöcke
	 * @param maxBlocks Die anzahl der maxmimal zu zerstörenden Blöcke - Wird durch die Schwirigkeitsstufe bestimmt.
	 * @return Die Punktzahl.
	 */
	unsigned int computeScore(unsigned int score, unsigned int destroyedBlocks, unsigned int maxBlocks);

	GLFWwindow* window_;
	SpriteManager* sprite_manager_;
	Screen* current_screen_;
	std::vector<Screen*> screens_;
	std::vector<std::string> level_files_;
	std::vector<Highscore*> scores_;
	unsigned int current_world_;
};

#endif /* GAME_H_ */
