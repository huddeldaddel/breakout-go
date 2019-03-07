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
	return
		this->getX1() == other.getX1() &&
		this->getX2() == other.getX2() &&
		this->getY1() == other.getY1() &&
		this->getY2() == other.getY2();
}

bool Line::operator!=(const Line& other) const {
	return !(*this == other);
}