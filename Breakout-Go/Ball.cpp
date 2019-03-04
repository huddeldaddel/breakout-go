#include <odroid_go.h>
#include "Ball.h"

const int DEFAULT_RADIUS = 3;
const float DEFAULT_SPEED = 4;
  
Ball::Ball(Slider& slider, void(&onDeath)()): onDeath{onDeath} {
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

void Ball::reset() {
  moving = false;
  speedX = 0;
  speedY = 0;
  radius = DEFAULT_RADIUS;
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
  
  if(positionX + radius >= (screenWidth - level.getBorderRight())) {                     // bounce off right
    positionX -= 2 *((positionX + radius) - (screenWidth - level.getBorderRight()));
    speedX *= -1;
  } else if (positionX - radius <= level.getBorderLeft()) {                              // bounce off left
    positionX -= 2 *((positionX - radius) - (level.getBorderLeft()));
    speedX *= -1;
  }

  if((speedY < 0) && (positionY - radius <= level.getBorderTop())) {                     // bounce off top
    positionY += 2 *(level.getBorderTop() - (positionY - radius));
    speedY *= -1;
  } else if((speedY > 0) &&                                                              // bounce off slider 
            (positionY + radius >= slider.getPositionY() + slider.getHeight()) &&            
            (positionY - speedY + radius < slider.getPositionY() + slider.getHeight())) {
    const float interceptX = (positionX - speedX) + speedX * ((slider.getPositionY() - radius - positionY) / speedY);
    if((interceptX >= slider.getPositionX()) && (interceptX <= slider.getPositionX() + slider.getWidth())) {
      positionY -= 2 *((positionY + radius) - slider.getPositionY());
      speedY *= -1; 
    } else if((interceptX < slider.getPositionX()) && (interceptX + radius >= slider.getPositionX())) {
      positionY -= 2 *((positionY + radius) - slider.getPositionY());
      speedY *= -1;
      speedX = abs(speedX) * -1;
    } else if((interceptX > slider.getPositionX() + slider.getWidth()) && (interceptX - radius -radius <= slider.getPositionX() + slider.getWidth())) {
      positionY -= 2 *((positionY + radius) - slider.getPositionY());
      speedY *= -1;
      speedX = abs(speedX);
    }
  }

  if (positionY > screenHeight) {                                                        // death!
    onDeath();
  }
  
}

void Ball::updatePositionOnSlider(Slider& slider) {
  positionX = slider.getPositionX() + slider.getWidth() / 2;
  positionY = slider.getPositionY() - radius;
}
