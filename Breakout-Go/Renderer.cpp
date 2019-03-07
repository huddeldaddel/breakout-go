#include "Renderer.h"

const unsigned int COLOR_BACKGROUND = 0x0000; /*   0,   0,   0 */
const unsigned int COLOR_BALL = 0xFFFF;		  /* 255, 255, 255 */	
const unsigned int COLOR_BORDER = 0xC618;	  /* 192, 192, 192 */
const unsigned int COLOR_SLIDER = 0x7BEF;	  /* 128, 128, 128 */ 

Renderer::Renderer(Device* device) : device{device} { }

void Renderer::clearScreen() {
	device->fillScreenRect(0, 0, device->getScreenWidth(), device->getScreenHeight(), COLOR_BACKGROUND);
}

void Renderer::renderRectangle(Rectangle* rect, const unsigned int color) {
	device->fillScreenRect(rect->getPositionX(), rect->getPositionY(), rect->getWidth(), rect->getHeight(), color);
}

void Renderer::renderBorders(Level* level) {
	Rectangle* rect = level->getBorderLeftRect();
	renderRectangle(rect, COLOR_BORDER);
	delete rect;

	rect = level->getBorderTopRect();
	renderRectangle(rect, COLOR_BORDER);
	delete rect;

	rect = level->getBorderRightRect();
	renderRectangle(rect, COLOR_BORDER);
	delete rect;
}

void Renderer::renderBall(Ball* ball, const unsigned int color) {
	device->fillScreenCircle(int(ball->getPositionX()), int(ball->getPositionY()), int(ball->getRadius()), color); 
}

void Renderer::renderBall(Ball* ball) {
	renderBall(ball, COLOR_BALL);
}

void Renderer::removeBall(Ball* ball) {
	renderBall(ball, COLOR_BACKGROUND);
}

void Renderer::removeSlider(Slider* slider) {
	Rectangle* rect = slider->toRect();
	renderRectangle(rect, COLOR_BACKGROUND);
	delete rect;
}

void Renderer::renderSlider(Slider* slider) {
	Rectangle* rect = slider->toRect();
	renderRectangle(rect, COLOR_SLIDER);
	delete rect;
}
