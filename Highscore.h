/*
 * Highscore.h
 *
 *  Created on: 20.06.2014
 *      Author: Chris
 */

#ifndef HIGHSCORE_H_
#define HIGHSCORE_H_

#include <vector>

class Highscore {
public:
	Highscore();
	~Highscore(){};
	void loadHighscore();
	void saveHighscore();
	void setHighscore(int score);
private:
	std::vector<int> *highscoreList_;
};

inline bool sortFunktion (int i,int j) { return (i>j); }

#endif /* HIGHSCORE_H_ */
