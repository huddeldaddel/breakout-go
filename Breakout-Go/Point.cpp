#include "Point.h"

Point::Point(float x, float y) : x{ x }, y{ y } {
}

Point::~Point() {
}

float Point::getX() const {
	return x;
}

float Point::getY() const {
	return y;
}