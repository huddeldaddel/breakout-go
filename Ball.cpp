#include <odroid_go.h>
#include "Ball.h"

const float DEFAULT_SPEED = 4;
  
Ball::Ball(Slider& slider) {
  updatePositionOnSlider(slider);
}

float Ball::getPositionX() {
  return positionX;
}

float Ball::getPositionY() {
  return positionY;
}

float Ball::getSpeedX() {
  return speedX;
}

float Ball::getSpeedY() {
  return speedY;
}

bool Ball::shouldStart() {
  return (GO.BtnA.isPressed() == 1) || (GO.BtnB.isPressed() == 1);
}
    
bool Ball::isMoving() {
  return !(0 == int(speedX)) && (0 == int(speedY));
}

void Ball::start() {
  speedX = DEFAULT_SPEED;
  if(GO.BtnB.isPressed() == 1) {
    speedX *= -1;
  }
  speedY = DEFAULT_SPEED * -1;
}

void Ball::updatePosition(Level& level, Slider& slider, unsigned int screenWidth, unsigned int screenHeight) {
  positionX += speedX;
  positionY += speedY;
}

void Ball::updatePositionOnSlider(Slider& slider) {
  positionX = slider.getPositionX() + slider.getWidth() / 2;
  positionY = slider.getPositionY() -3;
}
