#ifndef _BALL_
#define _BALL_

#include "Slider.h"

class Ball {
  private:
    bool moving;
    float positionX;
    float positionY;
    int radius;
    float speedX;
    float speedY;
    void(&onDeath)() ; 
  public:
    Ball(const float x, const float y, void(&onDeath)());

    float getPositionX();
    float getPositionY();
    int getRadius();
    float getSpeedX();
    float getSpeedY();
};

#endif
