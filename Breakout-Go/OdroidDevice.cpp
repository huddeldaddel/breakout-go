#include "OdroidDevice.h"

const int AUDIO_CHANNEL = 0;
const int VOLUME = 1;

OdroidDevice::OdroidDevice() {
  Serial.begin(115200);                                                                                     // Attach serial (so you can use the serial monitor of the IDE to inspect the log)  
}

OdroidDevice::~OdroidDevice() {
  Serial.end();
}

void OdroidDevice::beep(const double frequency) const {
  ledcSetup(AUDIO_CHANNEL, 2000, 8);
  ledcWriteTone(AUDIO_CHANNEL, frequency);
  ledcWrite(AUDIO_CHANNEL, VOLUME);    
}

void OdroidDevice::drawScreenRect(const int x, const int y, const int w, const int h, const unsigned int color) {
  GO.lcd.drawRect(x, y, w, h, color);
}

void OdroidDevice::fillScreenRect(const int x, const int y, const int w, const int h, const unsigned int color) {
  GO.lcd.fillRect(x, y, w, h, color);
}

void OdroidDevice::fillScreenCircle(const int x, const int y, const int r, const unsigned int color) {
  GO.lcd.fillCircle(x, y, r, color); 
}

int OdroidDevice::getScreenWidth() const {
  return TFT_HEIGHT;
}

int OdroidDevice::getScreenHeight() const {
  return TFT_WIDTH;
}


bool OdroidDevice::isButtonAPressed() const {
  return (GO.BtnA.isPressed() == 1);
}

bool OdroidDevice::isButtonBPressed() const {
  return (GO.BtnB.isPressed() == 1);
}

bool OdroidDevice::isDirectionDownPressed() const {
  return false;
}

bool OdroidDevice::isDirectionLeftPressed() const {
  return (2 == GO.JOY_X.isAxisPressed());  
}

bool OdroidDevice::isDirectionUpPressed() const {
  return false;
}

bool OdroidDevice::isDirectionRightPressed() const {
  return (1 == GO.JOY_X.isAxisPressed()); 
}

void OdroidDevice::mute() const {
  ledcWriteTone(AUDIO_CHANNEL, 0);
  ledcWrite(AUDIO_CHANNEL, 0);    
}

void OdroidDevice::play(const unsigned char* music_data) const {
  GO.Speaker.playMusic(music_data, 25000);
}

void OdroidDevice::print(const int lives, const long score) const {
  GO.lcd.setTextColor(BLACK);
  GO.lcd.setTextSize(1);
  GO.lcd.setCursor(10, 6);
  GO.lcd.println("Lives: ");
  GO.lcd.drawNumber((long)lives, 50, 6);
  
  GO.lcd.setCursor(100, 6);
  GO.lcd.println("Score: ");
  GO.lcd.drawNumber(score, 140, 6);
}

void OdroidDevice::sleep(const int millis) const {
  delay(millis);
}

void OdroidDevice::update() {
  GO.update();
}
