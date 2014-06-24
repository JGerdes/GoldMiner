/*
 * Vec2.h
 *
 *  Created on: 18.06.2014
 *      Author: Jonathan
 */

#ifndef VEC2_H_
#define VEC2_H_

#include <math.h>

/**
 * @author Jonathan Wiemers
 *
 * Vektor Klassen mit einem X und einem Y wert für die Bildschirmposition
 * Bietet außerdme die benötigten Funktionen zur Vektorrechnung an.
 *
 */
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
	/**
	 * Addition eines Vektor
	 *
	 * @param v Der zu addierende Vec2.
	 * @return Das aktuelle Objekt auf der Linken seite der Rechnung.
	 */
	Vec2& operator +=(const Vec2 &v) {
		x_ += v.x_;
		y_ += v.y_;
		return *this;
	}

	/**
	 * Division eines Vektor
	 *
	 * @param v Der zu dividierende Vec2.
	 * @return Das aktuelle Objekt auf der Linken seite der Rechnung.
	 */
	Vec2& operator -=(const Vec2 &v) {
		x_ -= v.x_;
		y_ -= v.y_;
		return *this;
	}

	/**
	 * Division eines Vektor.
	 *
	 * @param v Der zu dividierende Vec2.
	 * @return Ein neues Vec2 Objekt als ergebnis der division.
	 */
	Vec2& operator -(const Vec2 &v){
		return *(new Vec2(x_-v.x_, y_-v.y_));
	}

	/**
	 * Skaliert den Vektor um einen bestimmten Wert
	 *
	 * @param scalar Der Wert um den skaliert werden soll.
	 * @return Das aktuelle skalierte Objekt
	 */
	Vec2& operator *=(double scalar) {
		x_ *= scalar;
		y_ *= scalar;
		return *this;
	}

	/**
	 * Reduziert den Vektor um einen bestimmten Wert.
	 *
	 * @param scalar Der Wert um den reduziert werden soll.
	 * @return Das aktuelle reduzierte Objekt.
	 */
	Vec2& operator /=(double scalar) {
		x_ /= scalar;
		y_ /= scalar;
		return *this;
	}

	/**
	 * Berechnte die länge des Vektors
	 *
	 * @return Die länge des Vektors
	 */
	double length() const {
		return sqrt(pow(x_, 2) + pow(y_, 2));
	}

private:
	double x_, y_;

};

#endif /* VEC2_H_ */
