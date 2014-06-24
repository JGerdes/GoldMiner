#ifndef FONT_H_
#define FONT_H_

#include <string>
#include <vector>
#include "Sprite.h"
#include "../Vec2.h"

/**
 * @author Jonas Gerdes
 *
 * Ermöglicht das Zeichnen von Zeichenketten
 * Benötigt dazu ein Sprite, das alle darzustellenden Buchstaben enthält
 * sowie den Pfad zu einer Textdatei, die alle in dem Sprite dargestellten
 * Buchstaben enthält.
 */
class Font {
public:
	/**
	 * Lädt Textdatei mit Buchstaben und berechnet an dieser und dem Sprite
	 * die Dimensionen jedes Buchstabens
	 * @param font_sprite
	 * @param charPath
	 */
	Font(Sprite* font_sprite, std::string charPath);
	virtual ~Font();

	/**
	 * Zeichnet Text rechts oberhalb von der angegebenen Position.
	 * Nicht definierte Zeichen werden als Leerzeichen angezeigt
	 * @param pos Position, an der der Text gezeichnet werden soll
	 * @param text Zu zeichnenden text
	 */
	void draw_text(Vec2 pos, std::string text) const;

	/**
	 * Farbe für die Schrift ändern
	 * @param c
	 */
	void setColor(Color c);

	/**
	 * Größe des Textes ändern. Der Wert 1 entspricht dabei der originalen
	 * Größe aus der Bilddatei
	 * @param s
	 */
	void setSize(float s);

	/**
	 * Berechnet die Größe eines Textes in Pixel die dieser haben würde, wenn er in diesem
	 * Moment gezeichnet werden würde (also unter Einbezug der gesetzten Größe)
	 * @param text Zu Messender Text
	 * @return	Abmaße des Textes in Pixeln
	 */
	Vec2 computeDimension(std::string text) const;

private:
	Sprite* sprite_;
	unsigned int char_width_;
	unsigned int char_height_;
	unsigned int chars_per_row_;
	std::vector<char> chars_;
	float size_;

	/**
	 * Gibt die Position eines Buchstaben innerhalb des Sprites an
	 * @param c Buchstabe, nach dem gesucht werden soll
	 * @return Wenn der Buchstabe in dem Sprite vorkommt die entsprechende Position
	 * in Pixeln, sonst für beide Koordinaten -1
	 */
	Vec2 getPositionOfChar(char c) const;
};

#endif /* FONT_H_ */
