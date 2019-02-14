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
