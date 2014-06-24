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
			x_(0.0), y_(0.0) {
	}

	Vec2(double _x, double _y) :
			x_(_x), y_(_y) {
	}

	Vec2(const Vec2 &v) :
			x_(v.x_), y_(v.y_) {
	}
	virtual ~Vec2(){}

	double& getX() {
		return x_;
	}

	double& getY() {
		return y_;
	}

	double getX() const {
		return x_;
	}

	double getY() const {
		return y_;
	}

	Vec2& operator +=(const Vec2 &v) {
		x_ += v.x_;
		y_ += v.y_;
		return *this;
	}

	Vec2& operator -=(const Vec2 &v) {
		x_ -= v.x_;
		y_ -= v.y_;
		return *this;
	}

	Vec2& operator -(const Vec2 &v){
		return *(new Vec2(x_-v.x_, y_-v.y_));
	}

	Vec2& operator *=(double scalar) {
		x_ *= scalar;
		y_ *= scalar;
		return *this;
	}

	Vec2& operator /=(double scalar) {
		x_ /= scalar;
		y_ /= scalar;
		return *this;
	}

	double length() const {
		return sqrt(pow(x_, 2) + pow(y_, 2));
	}

	Vec2& normalize() {
		double length = this->length();
		x_ /= length;
		y_ /= length;
		return *this;
	}

	Vec2 & invert() {
		x_ = -x_;
		y_ = -y_;
		return *this;
	}

private:
	double x_, y_;

};

#endif /* VEC2_H_ */
