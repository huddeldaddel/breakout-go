#ifndef _SLIDER_
#define _SLIDER_

// #include <odroid_go.h>
#include "Level.h"

class Slider {
  private:
    float positionX;
    float positionY;
    int width;
    int height;
    float speed;  
  public:
    Slider(Level& level, unsigned int screenWidth, unsigned int screenHeight);
    
    float getPositionX();
    float getPositionY();
    int getWidth();
    int getHeight();
    float getSpeed();
    
    bool isMoving();
    void updatePosition(Level& level, int screenWidth);
};

#endif
