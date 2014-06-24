#include "World.h"
#include "../Game.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

World::World(SpriteManager* spriteManager, string map) :
		sprite_manager_(spriteManager), player_(
				new Player(
						sprite_manager_->getSprite("assets/graphics/mario.ppm"),
						Vec2(0, 0), Vec2(Game::window_width / 18, Game::window_height / 11))),
		map_(new vector<Block*>()),
		bg_map_(new vector<Block*>()),
		font_(new Font(sprite_manager_->getSprite("assets/fonts/consolas.ppm"),"assets/fonts/consolas.txt")),
		difficulty_(EASY_GAME),
		listener_(nullptr),
		gold_amount_(0){
	font_->setColor(Color(1,1,1));
	font_->setSize(2);
	this->readMap(map);
}

World::~World() {
	vector<Block*>::iterator iter = map_->begin();
	while(iter != map_->end()){
		delete (*iter++);
	}
	delete map_;
	vector<Block*>::iterator ator = bg_map_->begin();
	while(ator != bg_map_->end()){
		delete (*ator++);
	}
	delete bg_map_;
	delete player_;
	delete font_;


}


const Player* World::getPlayer() const{
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
		//-----DOWN-----
		py -= 5;
		if (by + bh >= py && py > by) {

			if ((bx <= px && px <= bx + bw) || (bx >= px && px + pw >= bx)) {
				bottom = block;
			}
		}
		//-------UP-----
		if (by <= py + ph+10 && by > py) {

			if ((bx <= px && px <= bx + bw) || (bx >= px && px + pw >= bx)) {

				top = block;
			}
		}
		//-----LEFT-----
		py += 5;
		px -= 5;

		if (bx + bw >= px && bx <= px) {
			if ((by <= py && py <= by + bh) || (by >= py && py + ph >= by)) {

				left = block;
			}
		}
		//-----RIGHT-----
		px += 10;
		if (bx <= px + pw && bx > px) {
			if ((by <= py && py <= by + bh) || (by >= py && py + ph >= by)) {

				right = block;
			}
		}
	}
	this->player_->setNearestBlocks(top, left, right, bottom);

}


void World::setDifficulty(difficulty d){
	difficulty_ = d;
}

Block* World::createBlock(Block::Type type, Sprite* sprite, int i, int rowCount) {
 	return new Block(type ,Vec2((Game::window_width / 16) * i,Game::window_height - (Game::window_height / 9) * (rowCount + 1)) , sprite);
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
			switch(ch[i]){
			case 'x':
				map_->push_back(createBlock(Block::dirt, sprite_manager_->getSprite("assets/graphics/dirt.ppm"), i, rowCount));
				break;
			case 'g':
				map_->push_back(createBlock(Block::grass, sprite_manager_->getSprite("assets/graphics/grass.ppm"),i, rowCount));
				break;
			case 's':
				map_->push_back(createBlock(Block::stone, sprite_manager_->getSprite("assets/graphics/stone.ppm"),i, rowCount));
				break;
			case 'a':
				map_->push_back(createBlock(Block::gold, sprite_manager_->getSprite("assets/graphics/gold.ppm"),i, rowCount));
				gold_amount_++;
				break;
			case 'p':
				player_->setPosition(Vec2((Game::window_width / 16) * i,
						4+Game::window_height - (Game::window_height / 9) * (rowCount+1)));
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
				bg_map_->push_back(new Block(Block::dirt, Vec2((Game::window_width / 16) * x, Game::window_height - (Game::window_height / 9) * (y+1)),
										sprite));
			}else{
				Sprite* sprite = sprite_manager_->getSprite("assets/graphics/stone.ppm");
				sprite->setColor(Color(darkness, darkness, darkness+0.05));
				bg_map_->push_back(new Block(Block::dirt, Vec2((Game::window_width / 16) * x, Game::window_height - (Game::window_height / 9) * (y+1)),
										sprite));
			}
		}

	}
}

void World::setWorldEventListener(WorldEventListener* listener){
	listener_ = listener;
}




void World::tick() {
	this->testCollision();
	vector<Block*>::iterator iter = map_->begin();
	while(iter != map_->end()){
		if((*iter)->isDestroyed()){
			if((*iter)->getType() == Block::gold){
				this->player_->addToScore();
			}else {
				this->player_->addToDestroyedBlocks();
				if(this->player_->getAllDestroyedBlocks() == difficulty_){
					listener_->onLose(player_->getScore(), player_->getAllDestroyedBlocks(), difficulty_);
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
	if(gold_amount_ == player_->getScore()){
		listener_->onWin(player_->getScore(), player_->getAllDestroyedBlocks(), difficulty_);
	}
	player_->tick();
}

void World::draw() const{
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
	score_text << "Tool:" <<round(((float)(player_->getAllDestroyedBlocks())/difficulty_)*100) << "%";
	font_->draw_text(Vec2(1100,640),score_text.str());
	player_->draw();

}
