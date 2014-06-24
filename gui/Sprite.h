#ifndef SPRITE_H_
#define SPRITE_H_

#include <string>
#include "../Vec2.h"
#include <GLFW/glfw3.h>
#include "ImageBuffer.h"

/**
 * @autor Jonas Gerdes
 *
 * Hällt die RGB werte für eine Farbe.
 */
class Color{
public:
	Color(float r=0, float g=0, float b=0):
		r(r),
		g(g),
		b(b){}
	float r, g, b;
};

/**
 * @author Jonas Gerdes, Jonathan Wiemers
 *
 * Hat die PPM Datei als ImageBuffer und die Farbe in der das Image gezeichnet werden soll.
 */
class Sprite {
public:

	Sprite(ImageBuffer* image_buffer);

	virtual ~Sprite(){}

	/**
	 * Zeichent das Image aus dem ImageBuffer an einer bestimmten Position, in einer bestimmten größe in einem Quadratischen surface.
	 *
	 * @param position Die Position an der das Image gezeichnet werden soll.
	 * @param dimension Die Dimension in der das Image gezeichnet werden soll.
	 * @param tex_start Der anfang des Auschnitts in dem gezeichnet werden soll.
	 * @param tex_end Das ende des Auschnitts in dem gezeichnet werden soll.
	 */
	void draw(const Vec2& position, const Vec2& dimension, const Vec2& tex_start = Vec2(0.0,0.0), const Vec2& tex_end = Vec2(1.0,1.0));

	unsigned int getWidth() const;
	unsigned int getHeight() const;
	Color& getColor();
	void setColor(const Color& color);

	/**
	 * Methoden zum Spiegeln an der vertikalen Achse.
	 */
	void flip();
	void flip(bool flipped);


private:
	ImageBuffer* image_buffer_;
	bool debug_;
	Color color_;
	bool flipped_;
};

#endif /* SPRITE_H_ */
