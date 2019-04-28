#include <odroid_go.h>

#include "Ball.h"
#include "Controller.h"
#include "Device.h"
#include "Level.h"
#include "MusicPlayer.h"
#include "OdroidDevice.h"
#include "Slider.h"
#include "Renderer.h"

const unsigned long LOOP_DELAY = 1000 / 33;                                                                 // we aim for 30 fps

OdroidDevice* device = new OdroidDevice();
MusicPlayer* musicPlayer = new MusicPlayer(device);
Controller* controller = new Controller(device, musicPlayer);
bool showMessage = true;

// Initialization
void setup() {
  GO.begin();
}

// Main loop
void loop() {
  const unsigned long frameStart = millis();
  
  device->update();                                                                                         // Refresh button states etc.
  if(controller->getLives() == 0) {
    if(showMessage) {
      showMessage = false;
      printWelcomeMessage(controller->isGameOver());
    }
    if(GO.BtnStart.isPressed() == 1) {      
      controller->startNewGame();
      showMessage = true;
    }  
  } else {  
    controller->updateGame();    
  }   
  
  const unsigned long duration = millis() - frameStart;
  const int delay = (int) (LOOP_DELAY - duration);
  if(delay > 0)
    device->sleep(delay);
}

void printWelcomeMessage(bool gameOver) {
  GO.lcd.setTextColor(WHITE);
  GO.lcd.setTextSize(2);
  GO.lcd.setCursor(95, device->getScreenHeight() / 2);
  GO.lcd.println("PRESS START");
  GO.lcd.setCursor(95, device->getScreenHeight() / 2 - 30);
  if(gameOver) {
    GO.lcd.println("GAME OVER !\n");    
    musicPlayer->playGameOver();
  } else {
    GO.lcd.println("BREAKOUT GO\n");
    musicPlayer->playGameStart();
  }
}
