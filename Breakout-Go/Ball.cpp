#include "Ball.h"
  
Ball::Ball(const float x, const float y, const int r) : positionX{ x }, positionY{ y }, radius{ r }, speedX{ 0 }, speedY{ 0 }, moving{ false } {
}

float Ball::getPositionX() const {
  return positionX;
}

void Ball::setPositionX(float x) {
	positionX = x;
}

float Ball::getPositionY() const {
  return positionY;
}

void Ball::setPositionY(float y) {
	positionY = y;
}

int Ball::getRadius() const {
  return radius;
}

void Ball::setRadius(int r) {
	radius = r;
}

float Ball::getSpeedX() const {
  return speedX;
}

void Ball::setSpeedX(float s) {
	speedX = s;
}

float Ball::getSpeedY() const {
  return speedY;
}

void Ball::setSpeedY(float s) {
	speedY = s;
}

bool Ball::isMoving() const {
	return moving;
}

void Ball::setMoving(bool m) {
	moving = m;
}

void Ball::invertMovementX() {
	speedX *= -1;
}

void Ball::invertMovementY() {
	speedY *= -1;
}
