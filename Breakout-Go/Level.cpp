#include "Level.h"

// Currently just some default values for an empty first level
Level::Level(Device* d) : device{d}, number{1}, borderLeft{5}, borderTop{5}, borderRight{5} {
}

int Level::getNumber() {
  return number;
}

int Level::getBorderLeft() {
  return borderLeft;
}

int Level::getBorderTop() {
  return borderTop;
}

int Level::getBorderRight() {
  return borderRight;
}

Rectangle Level::getBorderLeftRect() {
  return Rectangle{0, 0, borderLeft, device->getScreenHeight()};
}

Rectangle Level::getBorderTopRect() {
  return Rectangle{0, 0, device->getScreenWidth(), borderTop};
}

Rectangle Level::getBorderRightRect() {
  return Rectangle{device->getScreenWidth() - borderRight, 0, borderRight, device->getScreenHeight()};   
}
