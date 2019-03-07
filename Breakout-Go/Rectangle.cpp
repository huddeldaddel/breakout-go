#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h) : positionX{ x }, positionY{ y }, width{ w }, height{ h } {
}

Rectangle::~Rectangle() {
}

int Rectangle::getPositionX() const {
	return positionX;
}

int Rectangle::getPositionY() const {
	return positionY;
}

int Rectangle::getWidth() const {
	return width;
}

int Rectangle::getHeight() const {
	return height;
}

Line* Rectangle::getLeftBorder() const {
	return new Line(float(positionX), float(positionY), float(positionX), float(positionY + height));
}

Line* Rectangle::getTopBorder() const {
	return new Line(float(positionX), float(positionY), float(positionX + width), float(positionY));
}

Line* Rectangle::getBottomBorder() const {
	return new Line(float(positionX), float(positionY + height), float(positionX + width), float(positionY + height));
}

Line* Rectangle::getRightBorder() const {
	return new Line(float(positionX + width), float(positionY), float(positionX + width), float(positionY + height));
}

bool Rectangle::operator==(const Rectangle& other) const {
	return
		positionX == other.positionX &&
		positionY == other.positionY &&
		width == other.width &&
		height == other.height;
}

bool Rectangle::operator!=(const Rectangle& other) const {
	return !(*this == other);
}