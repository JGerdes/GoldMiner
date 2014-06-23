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

class Highscore {
public:
	Highscore(std::string path);
	~Highscore();
	void addScore(unsigned int score);
	void setHighscore(int score);
	std::vector<unsigned int> getTop(unsigned int amount);
private:
	std::string path_;
	std::vector<unsigned int> highscoreList_;
	void loadHighscore(std::string path);
	void saveHighscore(std::string path);
};

inline bool sortFunktion (int i,int j) { return (i>j); }

#endif /* HIGHSCORE_H_ */
