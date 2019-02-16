#include <odroid_go.h>
#include "Slider.h"

Slider::Slider(Level& level, unsigned int screenWidth, unsigned int screenHeight) : width{30}, height{3}, speed{5.5} {
  positionX = (screenWidth - level.getBorderLeft() - level.getBorderRight() - 30) / 2; 
  positionY = screenHeight -10;
}

bool Slider::isMoving() {
  return GO.JOY_X.isAxisPressed() != 0;
}

float Slider::getPositionX() {
  return positionX;
}

float Slider::getPositionY() {
  positionY;
}

int Slider::getWidth() {
  return width;
}

int Slider::getHeight() {
  return height;
}

float Slider::getSpeed() {
  return speed;
}

void Slider::updatePosition(Level& level, int screenWidth) {
  if(2 == GO.JOY_X.isAxisPressed()) 
    positionX -= speed;
  if(1 == GO.JOY_X.isAxisPressed()) 
    positionX += speed;
  if(positionX < float(level.getBorderLeft()))
    positionX = float(level.getBorderLeft());
  if(positionX > float(screenWidth - level.getBorderRight() - width))
    positionX = float(screenWidth - level.getBorderRight() - width);
}
