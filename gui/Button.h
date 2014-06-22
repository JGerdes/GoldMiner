/*
 * Button.h
 *
 *  Created on: 21.06.2014
 *      Author: Jonas
 */

#ifndef BUTTON_H_
#define BUTTON_H_

#include <string>
#include "../objects/Entity.h"
#include "io/MouseListener.h"
#include "Sprite.h"
#include "../Vec2.h"
#include "Font.h"

class ButtonHandler{
public:
	ButtonHandler(){}
	virtual ~ButtonHandler(){};
	virtual void onButtonClick(unsigned int id) = 0;
};

class Button : public Entity, public MouseListener{
public:
	Button(unsigned int id, Sprite* sprite, Vec2 position, Vec2 dimension);
	virtual ~Button();
	virtual void onMouseMove(Vec2 screen_pos, Vec2 delta);
	virtual void onButtonUp(int button, Vec2 screen_pos);
	virtual void onButtonDown(int button , Vec2 screen_pos);
	virtual void onScroll(Vec2 offset);

	virtual void setHandler(ButtonHandler* handler);
	virtual void setFont(Font* font);
	virtual void setText(std::string text);

	virtual void draw();
	virtual void tick(){}
private:
	unsigned int id_;
	bool isHovered_;
	ButtonHandler* handler_;
	Font* font_;
	std::string text_;
};

#endif /* BUTTON_H_ */
