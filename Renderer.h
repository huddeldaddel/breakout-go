#ifndef _RENDERER_
#define _RENDERER_

#include <odroid_go.h>
#include "Ball.h"
#include "Slider.h"

class Renderer {
  private:
    void renderBall(Ball& ball, unsigned int color);
    void renderSlider(Slider& slider, unsigned int color);
  public:
    Renderer();
    void clearScreen();

    void renderBall(Ball& ball);
    void removeBall(Ball& ball);
    
    void renderBorders(Level& level, unsigned int width, unsigned int height);

    void removeSlider(Slider& slider);
    void renderSlider(Slider& slider);
};

#endif
