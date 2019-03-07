#include "Rectangle.h"
#include "Slider.h"

Slider::Slider(const float positionX, const float positionY, const int width, const int height, const float speed) : positionX{positionX}, positionY{positionY}, width{width}, height{height}, speed{speed} {  
}

float Slider::getPositionX() const {
	return positionX;
}

void Slider::setPositionX(const float x) {
	positionX = x;
}

float Slider::getPositionY() const {
	return positionY;
}

void Slider::setPositionY(const float y) {
	positionY = y;
}

int Slider::getWidth() const {
	return width;
}

void Slider::setWidth(const int w) {
	width = w;
}

int Slider::getHeight() const {
	return height;
}

void Slider::setHeight(const int h) {
	height = h;
}

float Slider::getSpeed() const {
	return speed;
}

void Slider::setSpeed(const float s) {
	speed = s;
}

Rectangle* Slider::toRect() const {
	return new Rectangle(int(positionX), int(positionY), width, height);
}
