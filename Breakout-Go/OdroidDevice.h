#ifndef _ODROID_DEVICE_
#define _ODROID_DEVICE_

#include <odroid_go.h>
#include "Arduino.h"
#include "Device.h"

extern "C" {
  #include "esp32-hal-dac.h"
}

class OdroidDevice : public Device {
private:
public:
  OdroidDevice();
  ~OdroidDevice();

  void beep(const double frequency) const;

  void drawScreenRect(const int x, const int y, const int w, const int h, const unsigned int color);
  void fillScreenCircle(const int x, const int y, const int r, const unsigned int color);
  void fillScreenRect(const int x, const int y, const int w, const int h, const unsigned int color);
  
  int getScreenWidth() const;
  int getScreenHeight() const;

  bool isButtonAPressed() const;
  bool isButtonBPressed() const;
  bool isDirectionDownPressed() const;
  bool isDirectionLeftPressed() const;
  bool isDirectionUpPressed() const;
  bool isDirectionRightPressed() const;

  void mute() const;

  void play(const unsigned char* music_data) const;
  void print(const int lives, const long score) const;

  void sleep(const int millis) const;
  void update();
};


#endif
