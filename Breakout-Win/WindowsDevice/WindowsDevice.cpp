#include <windows.h>

#include "WindowsDevice.h"

WindowsDevice::WindowsDevice() {
		
}

void WindowsDevice::fillScreenRect(const int x, const int y, const int w, const int h, const unsigned int color) const {

}

int WindowsDevice::getScreenWidth() const {
	return 0;
}

int WindowsDevice::getScreenHeight() const {
	return 0;
}

bool WindowsDevice::isButtonAPressed() const {
	return (GetKeyState('X') < 0);
}

bool WindowsDevice::isButtonBPressed() const {
	return (GetKeyState('Y') < 0);
}

bool WindowsDevice::isDirectionDownPressed() const {
	return (GetKeyState(VK_DOWN) < 0);
}

bool WindowsDevice::isDirectionLeftPressed() const {
	return (GetKeyState(VK_LEFT) < 0);
}

bool WindowsDevice::isDirectionUpPressed() const {
	return (GetKeyState(VK_UP) < 0);
}

bool WindowsDevice::isDirectionRightPressed() const {
	return (GetKeyState(VK_RIGHT) < 0);
}

void WindowsDevice::sleep(const int millis) const {
	Sleep(millis);
}
