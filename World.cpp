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

World::World(SpriteManager* spriteManager) :
		sprite_manager_(spriteManager), player_(
				new Player(
						sprite_manager_->getSprite("assets/graphics/mario.ppm"),
						Vec2(0, 0), Vec2(1280.0 / 16, 720.0 / 9))), map_(
				new vector<Block*>()) {
	cout << "readmap" << endl;
	this->readMap("map.txt");
}

World::~World() {
//	size_t i = 0;
//	for(auto block : this->map){
//		delete block;
//		cout << i++ << endl;
//	}
	delete player_;
}

void World::testCollision() {
	cout << "testCollision" << endl;
	bool left, right, top, bottom;
	left = right = top = bottom = true;

	for (auto block : *map_) {

		double bx, by, bw, bh, px, py, pw, ph;
		bx = block->getPosition().getX();
		by = block->getPosition().getY();
		bw = block->getDimension().getX();
		bh = block->getDimension().getY();
		px = this->player_->getPosition().getX();
		py = this->player_->getPosition().getY();
		pw = this->player_->getDimension().getX();
		ph = this->player_->getDimension().getY();
		//-----UNTEN-----

		if (py + ph >= by) {

			if ((bx >= px && bx + bw >= px)  || (bx <= px + pw && bx + bw >= px+pw)) {
				cout << "bottom" << endl;
				bottom = false;
			}
		}
		//-----LINKS-----
		if (bx + bw < px - 10) {
			if ((by > py && (by + bh) < py) || (py > by && (py + ph) < by)) {
				cout << "left" << endl;
				left = false;
			}
		}
		//-----RECHTS-----
		if (bx > px + pw + 10) {
			if ((by > py && (by + bh) < py) || (py > by && (py + ph) < by)) {
				cout << "right" << endl;
				right = false;
			}
		}
	}
	this->player_->setMoveables(top, left, right, bottom);
}

void World::readMap(string fileName) {
	ifstream quelle(fileName);
	int rowCount = 0;

	if (!quelle) {
		cerr << "map.txt kann nicht geöffnet werden!\n";
	}
	char ch[17];
	for (int i = 0; i < 16; i++) {
		ch[i] = ' ';
	}
	while (quelle.getline(ch, sizeof(ch))) {
		for (int i = 0; i < 16; i++) {
			if (ch[i] == 'x') {
				//TODO block höhe und breite benutzen
				Block* block = new Block(Block::dirt,
						Vec2((1280.0 / 16) * i, (720.0 / 9) * rowCount),
						sprite_manager_->getSprite("assets/graphics/dirt.ppm"));
				map_->push_back(block);
				cout << "new Ground " << (1280.0 / 16) * i << " ,"
						<< (720.0 / 9) * rowCount << endl;
			}
			if (ch[i] == 's') {
				player_->setPosition(
						Vec2((1280.0 / 16) * i, (720.0 / 9) * rowCount));
				cout << "Player Pos " << 20 * i << " " << 20 * rowCount << endl;
			}
			ch[i] = ' ';
		}
		rowCount++;
	}
	cout << "rowcount:" << rowCount << endl;
}

void World::testBlockLife() {
//	for(unsigned int i=0; i<map.size(); i++)    {
//		if(map.at(i).getHp()<=0) {
//			map.erase(map.begin() + i);
//		}
//	}
}

void World::tick() {
	this->testCollision();
	player_->tick();
}

void World::draw() {

//cout << "draw blocks("<< map->size()<< ")" << endl;
	for (auto block : *map_) {
		block->draw();
	}

//cout << "draw player" << endl;
	player_->draw();
}
