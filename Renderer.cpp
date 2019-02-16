#include <odroid_go.h>
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

void Renderer::renderBorders(Level& level, unsigned int width, unsigned int height) {
  GO.lcd.fillRect(0, 0, level.getBorderLeft(), height, COLOR_BORDER);
  GO.lcd.fillRect(0, 0, width, level.getBorderTop(), COLOR_BORDER);
  GO.lcd.fillRect(width - level.getBorderRight(), 0, level.getBorderRight(), height, COLOR_BORDER);    
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

void Renderer::renderSlider(Slider& slider, unsigned int color) {
  GO.lcd.fillRect(int(slider.getPositionX()), int(slider.getPositionY()), slider.getWidth(), slider.getHeight(), color);
}

void Renderer::removeSlider(Slider& slider) {
  renderSlider(slider, COLOR_BACKGROUND);
}

void Renderer::renderSlider(Slider& slider) {
  renderSlider(slider, COLOR_SLIDER);
}
