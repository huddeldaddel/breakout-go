#ifndef _RENDERER_
#define _RENDERER_

#include "Ball.h"
#include "Block.h"
#include "Device.h"
#include "Level.h"
#include "Rectangle.h"
#include "Slider.h"

class Renderer {
  private:
    Device* device;
    void renderBall(Ball* ball, const unsigned int color);
	void renderRectangle(Rectangle* rect, const unsigned int color);
  public:
    Renderer(Device* device);
    
    void clearScreen();

    void renderBall(Ball* ball);
    void removeBall(Ball* ball);
    
	void renderBlock(Block* block);
	void removeBlock(Rectangle* rectangle);

    void renderBorders(Level* level);

	void renderScore(Level* level, int lives, long score);

    void removeSlider(Slider* slider);
    void renderSlider(Slider* slider);
};

#endif
