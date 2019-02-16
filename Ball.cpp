#include <odroid_go.h>
#include "Ball.h"

const int DEFAULT_RADIUS = 3;
const float DEFAULT_SPEED = 4;
  
Ball::Ball(Slider& slider) {
  radius = DEFAULT_RADIUS;
  updatePositionOnSlider(slider);
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

bool Ball::shouldStart() {
  return (GO.BtnA.isPressed() == 1) || (GO.BtnB.isPressed() == 1);
}
    
bool Ball::isMoving() {
  return moving;
}

void Ball::start() {
  moving = true;
  speedX = DEFAULT_SPEED;
  if(GO.BtnB.isPressed() == 1) {
    speedX *= -1;
  }
  speedY = DEFAULT_SPEED * -1;
}

void Ball::updatePosition(Level& level, Slider& slider, unsigned int screenWidth, unsigned int screenHeight) {
  positionX += speedX;
  positionY += speedY;
  
  if (positionX + radius >= (screenWidth - level.getBorderRight())) {                    // bounce off right
    positionX -= 2 *((positionX + radius) - (screenWidth - level.getBorderRight()));
    speedX *= -1;
  } else if (positionX - radius <= level.getBorderLeft()) {                              // bounce off left
    positionX -= 2 *((positionX - radius) - (level.getBorderLeft()));
    speedX *= -1;
  }

  if (positionY - radius <= level.getBorderTop()) {                                      // bounce off top
    positionY += 2 *((positionY - radius) + (level.getBorderTop()));
    speedY *= -1;
  } else if ((speedY > 0) && (positionY + radius >= slider.getPositionY()) && 
             (positionY - speedY + radius < slider.getPositionY()) && 
             (positionX >= slider.getPositionX()) && 
             (positionX <= slider.getPositionX() + slider.getWidth())) {
    positionY -= 2 *((positionY + radius) - slider.getPositionY());
    speedY *= -1;
  }

  if (positionY > screenHeight) {
    // Game over
  }
  
}

void Ball::updatePositionOnSlider(Slider& slider) {
  positionX = slider.getPositionX() + slider.getWidth() / 2;
  positionY = slider.getPositionY() - radius;
}
