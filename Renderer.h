#ifndef _RENDERER_
#define _RENDERER_

#include "Slider.h"

class Renderer {
  private:
  public:
    Renderer();
    void clearScreen();
    void renderBorders(Level& level, unsigned int width, unsigned int height);
    void renderSlider(Slider& slider, unsigned int color);
};

#endif
