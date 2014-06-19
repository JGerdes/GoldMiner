/*
 * Entity.cpp
 *
 *  Created on: 18.06.2014
 *      Author: Jonas
 */

#include "Entity.h"
#include "iostream"

using namespace std;

Entity::Entity(Sprite* sprite, Vec2 position, Vec2 dimension) :
		dimension_(dimension),
		position_(position),
		sprite_(sprite) {
}

Entity::~Entity(){

}

void Entity::draw() const {
	sprite_->draw(position_, dimension_);
}

Entity& Entity::setDimension(Vec2 dim) {
	this->dimension_ = dim;
	return *this;
}

Entity& Entity::setPosition(Vec2 pos) {
	this->destination_ = pos;
	return *this;
}
Vec2 Entity::getDestination() const {
	return this->destination_;
}

Vec2 Entity::getPosition() const {
	return Vec2(position_);
}

const Vec2& Entity::getDimension() const {
	return this->dimension_;
}

