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

World::World(SpriteManager* spriteManager):
		sprite_manager_(spriteManager),
		player(new Player(sprite_manager_->getSprite("assets/graphics/mario.ppm"),Vec2(0,0),  Vec2(1280.0/16,720.0/9))),
		map(new vector<Block*>()){
	cout << "readmap" << endl;
	this->readMap("map.txt");
}

World::~World(){
//	size_t i = 0;
//	for(auto block : this->map){
//		delete block;
//		cout << i++ << endl;
//	}
	delete player;
}

void World::readMap(string fileName) {
	ifstream quelle(fileName);
	int rowCount = 0;

	if (!quelle) {
			cerr << "map.txt kann nicht geöffnet werden!\n";
	}
	char ch[17];
	for(int i= 0; i< 16; i++) {
		ch[i] = ' ';
	}
	while (quelle.getline(ch, sizeof(ch))) {
		for(int i= 0; i< 16; i++) {
			if(ch[i] == 'x') {
				//TODO block höhe und breite benutzen
				Block* block = new Block(Block::dirt ,Vec2((1280.0/16)*i,(720.0/9)*rowCount), sprite_manager_->getSprite("assets/graphics/dirt.ppm"));
				map->push_back(block);
				cout << "new Ground " <<(1280.0/16)*i << " ," << (720.0/9)*rowCount << endl;
			}
			if(ch[i] == 's') {
				player->setPosition(Vec2((1280.0/16)*i,(720.0/9)*rowCount));
				cout << "Player Pos " << 20*i << " " << 20*rowCount << endl;
			}
			ch[i] = ' ';
		}
		rowCount++;
	}
	cout << "rowcount:" << rowCount << endl;
}

void World::testBlockLife(){
//	for(unsigned int i=0; i<map.size(); i++) {
//		if(map.at(i).getHp()<=0) {
//			map.erase(map.begin() + i);
//		}
//	}
}

void World::tick(){
	player->tick();
}

void World::draw(){

	//cout << "draw blocks("<< map->size()<< ")" << endl;
	for(auto block : *map){
		block->draw();
	}


	//cout << "draw player" << endl;
	player->draw();
}
