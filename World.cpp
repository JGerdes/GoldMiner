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

World::World(SpriteManager* spriteManager, string map) :
		sprite_manager_(spriteManager), player_(
				new Player(
						sprite_manager_->getSprite("assets/graphics/mario.ppm"),
						Vec2(0, 0), Vec2(1280.0 / 18, 720.0 / 11))),
		map_(new vector<Block*>()),
		bg_map_(new vector<Block*>()),
		font_(new Font(sprite_manager_->getSprite("assets/graphics/font.ppm"),"assets/graphics/font.txt")){
	font_->setColor(Color(1,1,1));
	font_->setSize(2);
	cout << "readmap" << endl;
	this->readMap(map);
}

World::~World() {
//	size_t i = 0;
//	for(auto block : this->map){
//		delete block;
//		cout << i++ << endl;
//	}
	delete player_;
	delete font_;
}

void World::onKeyDown(int key) {

}

void World::onKeyUp(int key) {

}

Player* World::getPlayer() const{
	return player_;
}

void World::testCollision() {

	Block* left, *right, *top, *bottom;
	left = right = top = bottom = nullptr;

	for (Block* block : *map_) {

		double bx, by, bw, bh, px, py, pw, ph;
		bx = block->getPosition().getX();
		by = block->getPosition().getY();
		bw = block->getDimension().getX();
		bh = block->getDimension().getY();
		px = this->player_->getDestination().getX();
		py = this->player_->getDestination().getY();
		pw = this->player_->getDimension().getX();
		ph = this->player_->getDimension().getY();
		//-----UNTEN-----

		py -= 5;
		if (by + bh >= py && py > by) {

			if ((bx <= px && px <= bx + bw) || (bx >= px && px + pw >= bx)) {

				bottom = block;
			}
		}

		//-------OBEN-----
		if (by <= py + ph+10 && by > py) {

			if ((bx <= px && px <= bx + bw) || (bx >= px && px + pw >= bx)) {

				top = block;
			}
		}

		//-----LINKS-----
		py += 5;
		px -= 5;

		if (bx + bw >= px && bx <= px) {
			if ((by <= py && py <= by + bh) || (by >= py && py + ph >= by)) {

				left = block;
			}
		}
		//-----RECHTS-----
		px += 10;
		if (bx <= px + pw && bx > px) {
			if ((by <= py && py <= by + bh) || (by >= py && py + ph >= by)) {

				right = block;
			}
		}


	}

	this->player_->setNearestBlocks(top, left, right, bottom);
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
						Vec2((1280.0 / 16) * i, 640 - (720.0 / 9) * rowCount),
						sprite_manager_->getSprite("assets/graphics/dirt.ppm"), 2);
				map_->push_back(block);
				cout << "new Ground " << (1280.0 / 16) * i << " ,"
						<< (720.0 / 9) * rowCount << endl;
			}
			if (ch[i] == 'g') {
				//TODO block höhe und breite benutzen
				Block* block = new Block(Block::dirt,
						Vec2((1280.0 / 16) * i, 640 - (720.0 / 9) * rowCount),
						sprite_manager_->getSprite("assets/graphics/grass.ppm"), 3);
				map_->push_back(block);
				cout << "new Ground " << (1280.0 / 16) * i << " ,"
						<< (720.0 / 9) * rowCount << endl;
			}
			if (ch[i] == 's') {
				//TODO block höhe und breite benutzen
				Block* block = new Block(Block::dirt,
						Vec2((1280.0 / 16) * i, 640 - (720.0 / 9) * rowCount),
						sprite_manager_->getSprite("assets/graphics/stone.ppm"), 6);
				map_->push_back(block);
				cout << "new Ground " << (1280.0 / 16) * i << " ,"
						<< (720.0 / 9) * rowCount << endl;
			}
			if (ch[i] == 'a') {
				//TODO block höhe und breite benutzen
				Block* block = new Block(Block::gold,
						Vec2((1280.0 / 16) * i, 640 - (720.0 / 9) * rowCount),
						sprite_manager_->getSprite("assets/graphics/gold.ppm"), 10);
				map_->push_back(block);
				cout << "new Ground " << (1280.0 / 16) * i << " ,"
						<< (720.0 / 9) * rowCount << endl;
			}
			if (ch[i] == 'p') {
				player_->setPosition(
						Vec2((1280.0 / 16) * i, 642 - (720.0 / 9) * rowCount));
				cout << "Player Pos " << 20 * i << " " << 20 * rowCount << endl;
			}
			ch[i] = ' ';
		}
		rowCount++;
	}

	for(size_t y=1; y<9; y++){
		for(size_t x=0; x <16; x++){

			float darkness = 0.8-y/12.0;
			if(y < 5){
				Sprite* sprite = sprite_manager_->getSprite("assets/graphics/dirt.ppm");
				sprite->setColor(Color(darkness, darkness, darkness+0.05));
				bg_map_->push_back(new Block(Block::dirt, Vec2((1280.0 / 16) * x, 640 - (720.0 / 9) * y),
										sprite, 2));
			}else{
				Sprite* sprite = sprite_manager_->getSprite("assets/graphics/stone.ppm");
				sprite->setColor(Color(darkness, darkness, darkness+0.05));
				bg_map_->push_back(new Block(Block::dirt, Vec2((1280.0 / 16) * x, 640 - (720.0 / 9) * y),
										sprite, 2));
			}
		}

	}

	cout << "rowcount:" << rowCount << endl;
}



void World::tick() {
	this->testCollision();
	vector<Block*>::iterator iter = map_->begin();
	while(iter != map_->end()){
		if((*iter)->isDestroyed()){
			if((*iter)->getType() == Block::gold){
				this->player_->addToScore();
				std::cout << "Picked up a gold" << std::endl;
				std::cout << "Current Score: " << this->player_->getScore() << std::endl;
			}else if((*iter)->getType() == Block::dirt){
				this->player_->addToDestroyedBlocks();
				std::cout << "Destroyed blocks: " << this->player_->getAllDestroyedBlocks() << std::endl;
				if(this->player_->getAllDestroyedBlocks() == this->HARD_GAME){
					std::cout << "GAME OVER" << std::endl;
					std::cout << "Score: " << this->player_->getScore() << std::endl;
					std::cout << "Destroyed blocks: " << this->player_->getAllDestroyedBlocks() << std::endl;
					this->setGameOver(true);
				}
			}
			map_->erase(iter);
			if(iter != map_->end()){
				++iter;
			}
		}else{
			++iter;
		}
	}

	player_->tick();
}

void World::draw() {

//cout << "draw blocks("<< map->size()<< ")" << endl;
	for (auto block : *bg_map_) {
		block->draw();
	}

	for (auto block : *map_) {
		block->draw();
	}

	stringstream score_text;
	score_text << "Score:" <<player_->getScore();
	font_->draw_text(Vec2(1100,680),score_text.str());
	score_text.str("");
	score_text << "Tool:" <<round(((float)(player_->getAllDestroyedBlocks())/HARD_GAME)*100) << "%";
	font_->draw_text(Vec2(1100,640),score_text.str());

//cout << "draw player" << endl;
	player_->draw();

}
