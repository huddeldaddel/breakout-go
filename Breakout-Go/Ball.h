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
    Ball(Slider& slider, void(&onDeath)());

    float getPositionX();
    float getPositionY();
    int getRadius();
    float getSpeedX();
    float getSpeedY();
    
    bool isMoving();
    void reset();
    void updatePosition(Level& level, Slider& slider, unsigned int screenWidth, unsigned int screenHeight);
    void updatePositionOnSlider(Slider& slider);
    bool shouldStart();
    void start();
};

#endif
