#include "Renderer.h"

const unsigned int COLOR_BACKGROUND = 0x0000; /*   0,   0,   0 */
const unsigned int COLOR_BALL = 0xFFFF;		  /* 255, 255, 255 */	
const unsigned int COLOR_BORDER = 0xC618;	  /* 192, 192, 192 */
const unsigned int COLOR_SLIDER = 0x7BEF;	  /* 128, 128, 128 */ 

Renderer::Renderer(Device* device) : device{device} { }

void Renderer::clearScreen() {
  device->fillScreenRect(0, 0, device->getScreenWidth(), device->getScreenHeight(), COLOR_BACKGROUND);
}

void Renderer::renderRectangle(Rectangle rect, unsigned int color) {
  device->fillScreenRect(rect.positionX, rect.positionY, rect.width, rect.height, color);
}

void Renderer::renderBorders(Level* level) {
  renderRectangle(level->getBorderLeftRect(), COLOR_BORDER);
  renderRectangle(level->getBorderTopRect(), COLOR_BORDER);
  renderRectangle(level->getBorderRightRect(), COLOR_BORDER);
}

void Renderer::renderBall(Ball* ball, unsigned int color) {
  device->fillScreenCircle(int(ball->getPositionX()), int(ball->getPositionY()), int(ball->getRadius()), color); 
}

void Renderer::renderBall(Ball* ball) {
  renderBall(ball, COLOR_BALL);
}

void Renderer::removeBall(Ball* ball) {
  renderBall(ball, COLOR_BACKGROUND);
}

void Renderer::removeSlider(Slider* slider) {
  renderRectangle(slider->toRect(), COLOR_BACKGROUND);
}

void Renderer::renderSlider(Slider* slider) {
  renderRectangle(slider->toRect(), COLOR_SLIDER);
}
