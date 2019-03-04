#ifndef _SLIDER_
#define _SLIDER_

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

    Rectangle toRect();
    bool isMoving();
    void reset(Level& level, unsigned int screenWidth, unsigned int screenHeight);
    void updatePosition(Level& level, int screenWidth);
};

#endif
