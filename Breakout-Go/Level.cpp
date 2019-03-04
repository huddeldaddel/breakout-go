#include <odroid_go.h>
#include "Level.h"

// Currently just some default values for an empty first level
Level::Level() : number{1}, borderLeft{5}, borderTop{5}, borderRight{5} {
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
  return Rectangle{0, 0, borderLeft, TFT_WIDTH};
}

Rectangle Level::getBorderTopRect() {
  return Rectangle{0, 0, TFT_HEIGHT, borderTop};
}

Rectangle Level::getBorderRightRect() {
  return Rectangle{TFT_HEIGHT - borderRight, 0, borderRight, TFT_WIDTH};   
}
