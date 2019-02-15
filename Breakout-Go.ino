#include <odroid_go.h>
#include "Level.h"
#include "Slider.h"

const unsigned long LOOP_DELAY = 1000 / 33;                                                                 // we aim for 30 fps
const unsigned int HEIGHT = TFT_WIDTH;
const unsigned int WIDTH = TFT_HEIGHT;
const unsigned int SLIDER_POSITION_Y = HEIGHT - 10;

Level currentLevel{};
Slider slider{currentLevel, WIDTH};

// Initialization
void setup() {
  GO.begin();

  clearScreen();
  drawBorders();
  drawSlider(TFT_LIGHTGREY);
}

void draw() {
  if(slider.isMoving()) {
    drawSlider(TFT_BLACK);  
    slider.updatePosition(currentLevel, WIDTH);
  }
  if(slider.isMoving())
    drawSlider(TFT_LIGHTGREY);
}

// Main loop
void loop() {
  GO.update();                            // Refresh button states etc.
  
  draw();
  
  delay(LOOP_DELAY);
}

void clearScreen() {
  GO.lcd.fillScreen(TFT_BLACK);
}

void drawBorders() {
  GO.lcd.fillRect(0, 0, currentLevel.getBorderLeft(), HEIGHT, TFT_LIGHTGREY);
  GO.lcd.fillRect(0, 0, WIDTH, currentLevel.getBorderTop(), TFT_LIGHTGREY);
  GO.lcd.fillRect(WIDTH - currentLevel.getBorderRight(), 0, currentLevel.getBorderRight(), HEIGHT, TFT_LIGHTGREY);    
}

void drawSlider(unsigned int color) {
  GO.lcd.fillRect(int(slider.getPositionX()), SLIDER_POSITION_Y, slider.getWidth(), slider.getHeight(), color);
}
