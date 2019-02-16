#include <odroid_go.h>
#include "Ball.h"
#include "Level.h"
#include "Slider.h"
#include "Renderer.h"

const unsigned long LOOP_DELAY = 1000 / 33;                                                                 // we aim for 30 fps
const unsigned int HEIGHT = TFT_WIDTH;
const unsigned int WIDTH = TFT_HEIGHT;

Level currentLevel{};
Slider slider{currentLevel, WIDTH, HEIGHT};
Ball ball{slider};
Renderer renderer{};

// Initialization
void setup() {
  GO.begin();

  renderer.clearScreen();
  renderer.renderBorders(currentLevel, WIDTH, HEIGHT);
  renderer.renderSlider(slider);
  renderer.renderBall(ball);
}

// Main loop
void loop() {
  GO.update();                                    // Refresh button states etc.
  
  bool ballStarted = false;
  if(!ball.isMoving() && ball.shouldStart()) {
    ball.start();
    ballStarted = true;
  }

  renderer.removeBall(ball);
  ball.updatePosition(currentLevel, slider, WIDTH, HEIGHT);
  renderer.renderBall(ball);

  if(slider.isMoving()) {
    renderer.removeSlider(slider);                // TODO: Improve this. Removing and repainting causes flickering  
    slider.updatePosition(currentLevel, WIDTH);
    if(!ball.isMoving()) {
      renderer.removeBall(ball);
      ball.updatePositionOnSlider(slider);
      renderer.renderBall(ball);
    }
  } 

  if(ballStarted || slider.isMoving()) {
    renderer.renderSlider(slider);
  }
  
  delay(LOOP_DELAY);
}
