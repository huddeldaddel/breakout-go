#ifndef _ODROID_DEVICE_
#define _ODROID_DEVICE_

#include <odroid_go.h>
#include "Device.h"

class OdroidDevice : public Device {
private:
public:
  OdroidDevice();
  ~OdroidDevice();

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

  void sleep(const int millis) const;
  void update();
};


#endif
