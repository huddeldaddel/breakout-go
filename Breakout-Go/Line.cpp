#include "Line.h"

Line::Line(float x1, float y1, float x2, float y2) : x1{ x1 }, x2{ x2 }, y1{ y1 }, y2{ y2 } {
}

Line::~Line() {
}

float Line::getX1() const {
	return x1;
}

float Line::getX2() const {
	return x2;
}

float Line::getY1() const {
	return y1;
}

float Line::getY2() const {
	return y2;
}

bool Line::operator==(const Line& other) const {
#ifdef _DEBUG	
	// Implementation for Windows
	float a = fabsf(x1 - other.x1);
	float b = fabsf(y1 - other.y1);
	float c = fabsf(x2 - other.x2);
	float d = fabsf(y2 - other.y2);
#else			
	// Implementation for the Odroid-Go
	float a = abs(x1 - other.x1);
	float b = abs(y1 - other.y1);
	float c = abs(x2 - other.x2);
	float d = abs(y2 - other.y2);
#endif
	return(a < 0.01f) && (b < 0.01f) && (c < 0.01f) && (d < 0.01f);
}

bool Line::operator!=(const Line& other) const {
	return !(*this == other);
}