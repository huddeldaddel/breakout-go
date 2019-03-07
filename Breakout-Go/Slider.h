#ifndef _SLIDER_
#define _SLIDER_

#include "Rectangle.h"

class Slider {
  private:
    float positionX;
    float positionY;
    int width;
    int height;
    float speed;  
  public:
    Slider(const float positionX, const float positionY, const int width, const int height, const float speed);
    
    float getPositionX() const;
    void setPositionX(const float x);
    
    float getPositionY() const;
    void setPositionY(const float y);
    
    int getWidth() const;
    void setWidth(const int w);
    
    int getHeight() const;
    void setHeight(const int h);
    
    float getSpeed() const;
    void setSpeed(const float s);

    Rectangle* toRect() const;
};

#endif
