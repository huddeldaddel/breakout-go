#ifndef _RENDERER_
#define _RENDERER_

#include "Ball.h"
#include "Device.h"
#include "Level.h"
#include "Rectangle.h"
#include "Slider.h"

class Renderer {
  private:
    Device* device;
    void renderRectangle(Rectangle rect, unsigned int color);
    void renderBall(Ball& ball, unsigned int color);
  public:
    Renderer(Device* device);
    
    void clearScreen();

    void renderBall(Ball& ball);
    void removeBall(Ball& ball);
    
    void renderBorders(Level& level);

    void removeSlider(Slider& slider);
    void renderSlider(Slider& slider);
};

#endif
