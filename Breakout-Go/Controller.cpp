#include "Controller.h"

Controller::Controller() {
  
}

Controller::~Controller() {
  
}

void Controller::resetSlider(Slider* slider, Level* level, Device* device) const {
  slider->setWidth(30);
  slider->setHeight(3);
  slider->setSpeed(5.5);
  slider->setPositionX(device->getScreenWidth() - level->getBorderLeft() - level->getBorderRight() - slider->getWidth()) / 2; 
  slider->setPositionY(device->getScreenHeight() -10);
}
