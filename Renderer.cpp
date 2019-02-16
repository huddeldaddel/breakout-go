#include <odroid_go.h>
#include "Renderer.h"

Renderer::Renderer() {
  
}

void Renderer::clearScreen() {
  GO.lcd.fillScreen(TFT_BLACK);
}

void Renderer::renderBorders(Level& level, unsigned int width, unsigned int height) {
  GO.lcd.fillRect(0, 0, level.getBorderLeft(), height, TFT_LIGHTGREY);
  GO.lcd.fillRect(0, 0, width, level.getBorderTop(), TFT_LIGHTGREY);
  GO.lcd.fillRect(width - level.getBorderRight(), 0, level.getBorderRight(), height, TFT_LIGHTGREY);    
}

void Renderer::renderSlider(Slider& slider, unsigned int color) {
  GO.lcd.fillRect(int(slider.getPositionX()), int(slider.getPositionY()), slider.getWidth(), slider.getHeight(), color);
}
