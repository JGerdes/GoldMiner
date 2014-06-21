/*
 * Vec2.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonathan
 */

#ifndef VEC2_H_
#define VEC2_H_

#include <math.h>

class Vec2 {
public:
	Vec2() :
			x(0.0), y(0.0) {
	}

	Vec2(double _x, double _y) :
			x(_x), y(_y) {
	}

	Vec2(const Vec2 &v) :
			x(v.x), y(v.y) {
	}
	virtual ~Vec2(){}

	double& getX() {
		return x;
	}

	double& getY() {
		return y;
	}

	double getX() const {
		return x;
	}

	double getY() const {
		return y;
	}

	Vec2& operator +=(const Vec2 &v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vec2& operator -=(const Vec2 &v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	Vec2& operator-(const Vec2 &v){
		return *(new Vec2(x-v.x, y-v.y));
	}

	Vec2& operator *=(double scalar) {
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vec2& operator /=(double scalar) {
		x /= scalar;
		y /= scalar;
		return *this;
	}

	double length() const {
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	Vec2& normalize() {
		double length = this->length();
		x /= length;
		y /= length;
		return *this;
	}

	Vec2 & invert() {
		x = -x;
		y = -y;
		return *this;
	}

private:
	double x, y;

};

#endif /* VEC2_H_ */
