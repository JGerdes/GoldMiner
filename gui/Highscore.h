/*
 * Highscore.h
 *
 *  Created on: 20.06.2014
 *      Author: Chris
 */

#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include <vector>
#include <string>

/**
 * @author Chris Brockhoff, Jonas Gerdes
 *
 * Verwaltet den Highscore eines Levels. L�dt diesen beim Erstellen
 * aus einer Textdatei und schreibt diese am Ende wieder in diese Datei.
 */
class Highscore {
public:
	/**
	 * L�dt Vektor mit Scores aus Textdatei und speichert diesen zwischen
	 * @param path Datei, aus der der Highscore geladen werden soll
	 */
	Highscore(std::string path);

	/**
	 * Speichert den Vektor mit Scores in die im Konstruktor angegebene Datei zur�ck.
	 */
	~Highscore();

	/**
	 * F�gt Score ans Ende des Vektor mit allen Scores ein.
	 * @param score Der zu speichernde Score
	 */
	void addScore(unsigned int score);

	/**
	 * Gibt einen abfallend sortierten Vektor mit den h�chsten Scores zur�ck.
	 * @param amount Anzahl der Eintr�ge
	 * @return Sortierter Vektor, der die besten amount Scores enth�lt
	 */
	std::vector<unsigned int> getTop(unsigned int amount);
private:
	std::string path_;
	std::vector<unsigned int> highscoreList_;
	void loadHighscore(std::string path);
	void saveHighscore(std::string path);
};

inline bool sortFunktion (int i,int j) { return (i>j); }

#endif /* HIGHSCORE_H_ */
