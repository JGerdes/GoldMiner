/*
 * World.cpp
 *
 *  Created on: 02.06.2014
 *      Author: Chris
 */

#include "World.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

World::World(): collisonRight(false), collisionLeft(false),
		collisionDown(false), collisionUp(false) {
	map = createMap();
}

vector<Ground> World::createMap() {
	vector<Ground> map;
	ifstream quelle("map.txt");
	int rowCount = 0;

	if (!quelle) {
			cerr << "map.txt kann nicht geöffnet werden!\n";
			exit(-1);
	}

	while (true) {
		char ch[21];
		quelle.getline(ch, sizeof(ch));

		if (ch[0] == '#') {
			break;
		}

		for(int i= 0; i< 20; i++) {
			if(ch[i] == 'x') {
				//TODO block höhe und breite benutzen
				Ground ground(20*i,20*rowCount);
				map.push_back(ground);
				cout << "new Ground " << 20*i << " " << 20*rowCount << endl;
			}
			if(ch[i] == 's') {
				player.setPos(20*i,20*rowCount);
				cout << "Player Pos " << 20*i << " " << 20*rowCount << endl;
			}
		}
		rowCount++;
	}
	return map;
}

void World::testBlockLife(){
	for(unsigned int i=0; i<map.size(); i++) {
		if(map.at(i).getHp()<=0) {
			map.erase(map.begin() + i);
		}
	}
}
