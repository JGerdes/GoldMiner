/*
 * Font.h
 *
 *  Created on: 21.06.2014
 *      Author: Jonas
 */

#ifndef FONT_H_
#define FONT_H_

#include <string>
#include <vector>
#include "Sprite.h"
#include "Vec2.h"

class Font {
public:
	Font(Sprite* font_sprite, std::string charPath);
	virtual ~Font();

	void draw_text(Vec2 pos, std::string text) const;
	void setColor(Color c);
	void setSize(float s);

private:
	Sprite* sprite_;
	unsigned int char_width_;
	unsigned int char_height_;
	unsigned int chars_per_row_;
	std::vector<char> chars_;
	float size_;

	Vec2 getPositionOfChar(char c) const;
};

#endif /* FONT_H_ */
