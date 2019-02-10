#include <odroid_go.h>

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

struct level {
  int number;
  int borderLeft;
  int borderTop;
  int borderRight;
};

typedef struct level Level;

Level currentLevel;
Slider slider;

// Initialization
void setup() {
  GO.begin();
  
  initializeLevel();
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
  GO.lcd.fillRect(0, 0, currentLevel.borderLeft, HEIGHT, TFT_LIGHTGREY);
  GO.lcd.fillRect(0, 0, WIDTH, currentLevel.borderTop, TFT_LIGHTGREY);
  GO.lcd.fillRect(WIDTH - currentLevel.borderRight, 0, currentLevel.borderRight, HEIGHT, TFT_LIGHTGREY);    
}

void drawSlider(unsigned int color) {
  GO.lcd.fillRect(int(slider.positionX), SLIDER_POSITION_Y, slider.width, slider.height, color);
}

// Fill currentLevel some some useful values for first tests
void initializeLevel() {
  currentLevel.number = 1;
  currentLevel.borderLeft = 5;
  currentLevel.borderTop = 5;
  currentLevel.borderRight = 5;
}

void initializeSlider() {
  slider.width = 30;
  slider.height = 3;
  slider.positionX = (WIDTH - currentLevel.borderLeft - currentLevel.borderRight - slider.width) / 2;
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
  if(slider.positionX < float(currentLevel.borderLeft))
    slider.positionX = float(currentLevel.borderLeft);
  if(slider.positionX > float(WIDTH - currentLevel.borderRight - slider.width))
    slider.positionX = float(WIDTH - currentLevel.borderRight - slider.width);
}
