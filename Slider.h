#ifndef _SLIDER_
#define _SLIDER_

#include <odroid_go.h>
#include "Level.h"

class Slider {
  private:
    float positionX;
    int width;
    int height;
    float speed;  
  public:
    Slider(Level& level, int screenWidth);
    
    bool isMoving();
    float getPositionX();
    int getWidth();
    int getHeight();
    float getSpeed();

    void updatePosition(Level& level, int screenWidth);
};

#endif
