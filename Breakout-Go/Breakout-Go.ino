#include <odroid_go.h>
#include "Ball.h"
#include "Level.h"
#include "Slider.h"
#include "Renderer.h"

const unsigned long LOOP_DELAY = 1000 / 33;                                                                 // we aim for 30 fps
const unsigned int HEIGHT = TFT_WIDTH;
const unsigned int WIDTH = TFT_HEIGHT;
const int DEFAULT_LIFE_COUNT = 3;

Level currentLevel{};
Slider slider{currentLevel, WIDTH, HEIGHT};

int lives = 0;
bool gameOver = false;
Renderer renderer{};
Ball ball{slider, handleDeath};

// Initialization
void setup() {
  GO.begin();
  GO.lcd.setTextSize(2);
}

void handleDeath() {
  lives -= 1;
  if (lives > 0) {
    renderer.removeSlider(slider);
    
    slider.reset(currentLevel, WIDTH, HEIGHT);
    ball.reset();
    ball.updatePositionOnSlider(slider);

    renderer.renderSlider(slider);
    renderer.renderBall(ball);
  } else {
    gameOver = true;
  }
}

// Main loop
void loop() {
  GO.update();                                    // Refresh button states etc.

  if(lives == 0) {
    printWelcomeMessage();
    if(GO.BtnStart.isPressed() == 1) {
      startNewGame();
    }  
  } else {  
    bool ballStarted = false;
    if(!ball.isMoving() && ball.shouldStart()) {
      ball.start();
      ballStarted = true;
    }
  
    renderer.removeBall(ball);
    ball.updatePosition(currentLevel, slider, WIDTH, HEIGHT);
    renderer.renderBall(ball);
  
    if(slider.isMoving()) {
      renderer.removeSlider(slider);
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
  }   
  
  delay(LOOP_DELAY);
}

void printWelcomeMessage() {
  GO.lcd.setCursor(95, HEIGHT / 2 - 30);
  if(gameOver) {
    GO.lcd.println("GAME OVER !\n");
  } else {
    GO.lcd.println("BREAKOUT GO\n");
  }
  GO.lcd.setCursor(95, HEIGHT / 2);
  GO.lcd.println("PRESS START");
}

void startNewGame() {
  lives = DEFAULT_LIFE_COUNT;
  gameOver = false;

  renderer.clearScreen();
  renderer.renderBorders(currentLevel);
  renderer.renderSlider(slider);
  renderer.renderBall(ball);
}
