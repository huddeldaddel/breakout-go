#include <odroid_go.h>
#include "Level.h"

const unsigned long LOOP_DELAY = 1000 / 33;                                                                 // we aim for 30 fps
const unsigned int HEIGHT = TFT_WIDTH;
const unsigned int WIDTH = TFT_HEIGHT;
const unsigned int SLIDER_POSITION_Y = HEIGHT - 10;

struct slider {
  float positionX;
  int width;
  int height;
  float speed;
};

typedef struct slider Slider;

Level currentLevel{};
Slider slider;

// Initialization
void setup() {
  GO.begin();
  
  initializeSlider();

  clearScreen();
  drawBorders();
  drawSlider(TFT_LIGHTGREY);
}

void draw() {
  if(isSliderMoving()) {
    drawSlider(TFT_BLACK);  
    updateSliderPosition();
  }
  if(isSliderMoving())
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
  GO.lcd.fillRect(int(slider.positionX), SLIDER_POSITION_Y, slider.width, slider.height, color);
}

void initializeSlider() {
  slider.width = 30;
  slider.height = 3;
  slider.positionX = (WIDTH - currentLevel.getBorderLeft() - currentLevel.getBorderRight() - slider.width) / 2;
  slider.speed = 5.5; 
}

boolean isSliderMoving() {
  return GO.JOY_X.isAxisPressed() != 0;
}

void updateSliderPosition() {
  if(2 == GO.JOY_X.isAxisPressed()) 
    slider.positionX -= slider.speed;
  if(1 == GO.JOY_X.isAxisPressed()) 
    slider.positionX += slider.speed;
  if(slider.positionX < float(currentLevel.getBorderLeft()))
    slider.positionX = float(currentLevel.getBorderLeft());
  if(slider.positionX > float(WIDTH - currentLevel.getBorderRight() - slider.width))
    slider.positionX = float(WIDTH - currentLevel.getBorderRight() - slider.width);
}
