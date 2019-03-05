#include "Ball.h"

const int DEFAULT_RADIUS = 3;
const float DEFAULT_SPEED = 4;
  
Ball::Ball(const float x, const float y, void(&onDeath)()) : positionX{ x }, positionY{ y }, radius{ DEFAULT_RADIUS }, speedX{ 0 }, speedY{ 0 }, onDeath{ onDeath } {
}

float Ball::getPositionX() {
  return positionX;
}

float Ball::getPositionY() {
  return positionY;
}

int Ball::getRadius() {
  return radius;
}

float Ball::getSpeedX() {
  return speedX;
}

float Ball::getSpeedY() {
  return speedY;
}

