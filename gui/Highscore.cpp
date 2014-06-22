/*
 * Highscore.cpp
 *
 *  Created on: 20.06.2014
 *      Author: Chris
 */

#include "Highscore.h"
#include <vector>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <strstream>

using namespace std;

Highscore::Highscore() :
		highscoreList_(new vector<int>()) {
	loadHighscore();
}

void Highscore::loadHighscore() {
	highscoreList_->clear();
	ifstream quelle("highscore.txt");

	if (!quelle) {
		cerr << "highscore.txt kann nicht geöffnet werden!\n";
	}
	char ch[17];
	for (int i = 0; i < 16; i++) {
		ch[i] = ' ';
	}
	string score;
	while (quelle.getline(ch, sizeof(ch))) {
		score.clear();
		for (int i = 0; i < 16; i++) {
			if (ch[i] != ' ') {
				score = score + ch[i];
			}
		}
		highscoreList_->push_back(atoi(score.c_str()));
	}

	sort(highscoreList_->begin(), highscoreList_->end(), sortFunktion);
	while (highscoreList_->size() > 10) {
		highscoreList_->pop_back();
	}

}

void Highscore::saveHighscore() {
	ofstream quelle("highscore.txt");

	if (!quelle) {
		cerr << "highscore.txt kann nicht geöffnet werden!\n";
	}

	for (size_t i = 0; i < highscoreList_->size(); i++) {
		quelle << highscoreList_->at(i) << endl;
	}

	for (unsigned int i = 0; i < highscoreList_->size(); i++)
			cout << highscoreList_->at(i) << endl;
}

void Highscore::setHighscore(int score) {

	highscoreList_->push_back(score);
	sort(highscoreList_->begin(), highscoreList_->end(), sortFunktion);
	while (highscoreList_->size() > 10) {
		highscoreList_->pop_back();
	}
	saveHighscore();

}
