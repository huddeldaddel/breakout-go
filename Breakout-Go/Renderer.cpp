#include <odroid_go.h>
#include "Rectangle.h"
#include "Renderer.h"

const unsigned int COLOR_BACKGROUND = TFT_BLACK;
const unsigned int COLOR_BALL = TFT_WHITE;
const unsigned int COLOR_BORDER = TFT_LIGHTGREY;
const unsigned int COLOR_SLIDER = TFT_LIGHTGREY;

Renderer::Renderer() { 
}

void Renderer::clearScreen() {
  GO.lcd.fillScreen(COLOR_BACKGROUND);
}

void Renderer::renderRectangle(Rectangle rect, unsigned int color) {
  GO.lcd.fillRect(rect.positionX, rect.positionY, rect.width, rect.height, color);
}

void Renderer::renderBorders(Level& level) {
  renderRectangle(level.getBorderLeftRect(), COLOR_BORDER);
  renderRectangle(level.getBorderTopRect(), COLOR_BORDER);
  renderRectangle(level.getBorderRightRect(), COLOR_BORDER);
}

void Renderer::renderBall(Ball& ball, unsigned int color) {
  GO.lcd.fillCircle(ball.getPositionX(), ball.getPositionY(), ball.getRadius(), color); 
}

void Renderer::renderBall(Ball& ball) {
  renderBall(ball, COLOR_BALL);
}

void Renderer::removeBall(Ball& ball) {
  renderBall(ball, COLOR_BACKGROUND);
}

void Renderer::removeSlider(Slider& slider) {
  renderRectangle(slider.toRect(), COLOR_BACKGROUND);
}

void Renderer::renderSlider(Slider& slider) {
  renderRectangle(slider.toRect(), COLOR_SLIDER);
}
