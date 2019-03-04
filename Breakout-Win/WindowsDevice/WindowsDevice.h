#ifndef _WINDOWS_DEVICE_
#define _WINDOWS_DEVICE_

#include "../../Breakout-Go/Device.h"

class WindowsDevice : public Device {
public:
	WindowsDevice();

	void fillScreenRect(const int x, const int y, const int w, const int h, const unsigned int color) const;

	int getScreenWidth() const;
	int getScreenHeight() const;

	bool isButtonAPressed() const;
	bool isButtonBPressed() const;
	bool isDirectionDownPressed() const;
	bool isDirectionLeftPressed() const;
	bool isDirectionUpPressed() const;
	bool isDirectionRightPressed() const;

	void sleep(const int millis) const;
};

#endif
