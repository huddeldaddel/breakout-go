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