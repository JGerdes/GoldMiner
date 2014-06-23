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
#include <sstream>

using namespace std;

Highscore::Highscore(string path):
	path_(path){
	loadHighscore(path);
}

Highscore::~Highscore(){
	saveHighscore(path_);
}

void Highscore::loadHighscore(string path) {
	highscoreList_.clear();
	ifstream quelle(path);

	if (!quelle) {
		cerr << "Error while loading Highscore: '"<< path <<"' couldn't be opened!" << endl;
	}
	string line;
	while (getline(quelle, line)) {
		unsigned int score;
		istringstream (line) >> score;
		highscoreList_.push_back(score);
	}

}

void Highscore::saveHighscore(string path) {

	ofstream quelle(path);

	if (!quelle) {
		cerr << "Error while saving Highscore: '"<< path <<"' couldn't be opened!" << endl;
	}

	for (size_t i = 0; i < highscoreList_.size(); i++) {
		quelle << highscoreList_.at(i) << endl;
	}

}

void Highscore::addScore(unsigned int score) {

	highscoreList_.push_back(score);
}

vector<unsigned int> Highscore::getTop(unsigned int amount){
	cout << "Highscore:: get top " << amount << endl;
	vector<unsigned int> top;
	for(int score : highscoreList_){
		top.push_back(score);
	}
	sort(top.begin(), top.end(), sortFunktion);
	while (top.size() > amount) {
		top.pop_back();
	}
	cout << "Highscore:: get top " << amount << "ready" <<endl;
	return top;
}


