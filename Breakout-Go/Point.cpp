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

bool Point::operator==(const Point& other) const {
#ifdef _DEBUG	
	// Implementation for Windows
	float a = fabsf(x - other.x);
	float b = fabsf(y - other.y);
#else			
	// Implementation for the Odroid-Go
	float a = abs(x - other.x);
	float b = abs(y - other.y);
#endif
	return (a < 0.01f) && (b < 0.01f);
}

bool Point::operator!=(const Point& other) const {
	return !(*this == other);
}