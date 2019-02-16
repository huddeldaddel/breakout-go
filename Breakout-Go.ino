#include <odroid_go.h>
#include "Level.h"
#include "Slider.h"
#include "Renderer.h"

const unsigned long LOOP_DELAY = 1000 / 33;                                                                 // we aim for 30 fps
const unsigned int HEIGHT = TFT_WIDTH;
const unsigned int WIDTH = TFT_HEIGHT;

Level currentLevel{};
Slider slider{currentLevel, WIDTH, HEIGHT};
Renderer renderer{};

// Initialization
void setup() {
  GO.begin();

  renderer.clearScreen();
  renderer.renderBorders(currentLevel, WIDTH, HEIGHT);
  renderer.renderSlider(slider, TFT_LIGHTGREY);
}

// Main loop
void loop() {
  GO.update();                            // Refresh button states etc.
  
  draw();
  
  delay(LOOP_DELAY);
}

void draw() {
  if(slider.isMoving()) {
    renderer.renderSlider(slider, TFT_BLACK);  
    slider.updatePosition(currentLevel, WIDTH);
  }
  if(slider.isMoving())
    renderer.renderSlider(slider, TFT_LIGHTGREY);
}
