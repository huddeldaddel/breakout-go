#ifndef _RENDERER_
#define _RENDERER_

#include "Ball.h"
#include "Rectangle.h"
#include "Slider.h"

class Renderer {
  private:
    void renderRectangle(Rectangle rect, unsigned int color);
    void renderBall(Ball& ball, unsigned int color);
  public:
    Renderer();
    
    void clearScreen();

    void renderBall(Ball& ball);
    void removeBall(Ball& ball);
    
    void renderBorders(Level& level);

    void removeSlider(Slider& slider);
    void renderSlider(Slider& slider);
};

#endif
