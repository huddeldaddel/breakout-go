#include <odroid_go.h>

#include "Ball.h"
#include "Controller.h"
#include "Device.h"
#include "Level.h"
#include "OdroidDevice.h"
#include "Slider.h"
#include "Renderer.h"

const unsigned long LOOP_DELAY = 1000 / 33;                                                                 // we aim for 30 fps

OdroidDevice* device = new OdroidDevice();
Controller* controller = new Controller(device);

// Initialization
void setup() {
  GO.begin();
  GO.lcd.setTextSize(2);
}

// Main loop
void loop() {
  device->update();                                    // Refresh button states etc.

  if(controller->getLives() == 0) {
    printWelcomeMessage();
    if(GO.BtnStart.isPressed() == 1) {
      controller->startNewGame();
    }  
  } else {  
    controller->updateGame();
  }   
  
   device->sleep(LOOP_DELAY);
}

void printWelcomeMessage() {
  GO.lcd.setCursor(95, device->getScreenHeight() / 2 - 30);
  if(controller->isGameOver()) {
    GO.lcd.println("GAME OVER !\n");
  } else {
    GO.lcd.println("BREAKOUT GO\n");
  }
  GO.lcd.setCursor(95, device->getScreenHeight() / 2);
  GO.lcd.println("PRESS START");
}
