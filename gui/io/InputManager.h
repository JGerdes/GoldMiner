#ifndef INPUTMANAGER_H_
#define INPUTMANAGER_H_

#include <tr1/unordered_map>
#include <vector>
#include <GLFW/glfw3.h>
#include "MouseListener.h"
#include "KeyListener.h"


/**
 * @author Jonas Gerdes, Jonathan Wiemers
 *
 * Singleton, organisiert die Benutzereingaben. Leitet Events von
 * GLFW an registierte Listener weiter. Speichert Zustände von Tasten (gedrückt, nicht gedrückt)
 */
class InputManager {
public:

	/**
	 * Gibt die Singleton-Instanz zurück. Wird beim ersten Aufruf erzeugt
	 * @return Immergleiche Instanz von InputManager
	 */
    static InputManager& getInstance();

    /**
     * Callback Methoden für GLFW. Statisch, da direkte Zeiger auf diese bennötigt werden.
     * Rufen die Implementierungen des Singeltons auf
     * Für weitere Informationen: http://www.glfw.org/docs/latest/group__input.html
     */
	static void onMouseMove(GLFWwindow *window, double x, double y);
	static void onKey(GLFWwindow *window, int key, int scancode, int action, int mods);
	static void onButton(GLFWwindow *window, int button, int action, int mods);
	static void onScroll(GLFWwindow *window, double x_offset, double y_offset);
	static void onResize(GLFWwindow * window, int width, int height);

	/**
	 * Wird aufgerufen, wenn die Maus bewegt wird.
	 * Gibt allen MouseListenern Bescheid
	 * @param x Position der Maus in x-Richtung
	 * @param y Position der Maus in y-Richtung
	 */
    void onMouseMoveImpl(double x, double y);

    /**
     * Wird aufgerufen, wenn eine Taste gedrückt oder losgelassen wird
     * Gibt allen KeyListenern Bescheid.
     * @param key Eindeutige Nummer der Taste (GLFW Konstante)
     * @param action Gibt an, ob das Event aufgrund von Drücken, Loslassen oder Festhalten
     * der Taste ausgeführt wurde
     */
	void onKeyImpl(int key, int action);

	/**
	 * Wird aufgerufen, wenn eine Maustaste gedrückt wird.
	 * Gibt solange allen MouseListenern Bescheid, bis einer der Listener ein true zurück gibt
	 * @p@param button Eindeutige Nummer des Buttons (GLFW Konstante)
     * @param action Gibt an, ob das Event aufgrund von Drücken, Loslassen oder Festhalten
     * des Buttons ausgeführt wurde
	 */
	void onButtonImpl(int button, int action);

	/**
	 * Wird aufgerufen, wenn das Scrollrad der Maus gedreht wird.
	 * Gibt allen MouseListenern Bescheid
	 * Wird zur Zeit nicht benötigt, der Vollständigkeit wegen aber implementiert
	 * @param x_offset
	 * @param y_offset
	 */
	void onScrollImpl(double x_offset, double y_offset);

	/**
	 * Wird aufgerufen, wenn die Fenstergröße geändert wird
	 * Ändert die globalen Variablen Game::window_height und Game::window_width
	 * @param width Neue Breite des Fensters
	 * @param height Neue Höhe des Fensters
	 */
	void onResizeImpl(int width, int height);

	/**
	 * Neuen Listener für Mausevents aufnehmen
	 * @param listener Neuer Mauslistener
	 */
	void addMouseListener(MouseListener* listener);

	/**
	 * Neuen Listener für Tastaturevents aufnehmen
	 * @param listener Neuer Tastaturlistener
	 */
	void addKeyListener(KeyListener* listener);

	/**
	 * Gibt Auskunft über den Zustand einer Taste
	 * @param key Eindeutiger Tastencode, GLFW Konstante
	 * @return	true, wenn die entsprechende Taste gerade gedrückt ist, sonst false
	 */
	bool isKeyDown(int key);

	/**
	 * Gibt Auskunft über den Zustand einer Maustaste
	 * @param key Eindeutiger Tastencode, GLFW Konstante
	 * @return	true, wenn die entsprechende Taste gerade gedrückt ist, sonst false
	 */
	bool isButtonDown(int button);

	/**
	 * Nicht implementierte Kopierkonstruktor und Zuweisungsoperator, um
	 * zu verhindern, dass mehr als ein InputManager existieren (Singleton)
	 * @param
	 */
	InputManager(InputManager const&);
	void operator=(InputManager const&);

private:
	InputManager();
    std::tr1::unordered_map<int, bool> keys_;
    std::tr1::unordered_map<int, bool> mouse_buttons_;

    std::vector<MouseListener*> mouse_listeners_;
    std::vector<KeyListener*> key_listeners_;

    double last_x = 0;
	double last_y = 0;


};

#endif /* INPUTMANAGER_H_ */
