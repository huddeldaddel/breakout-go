#include <windows.h>

#include "WindowsDevice.h"

WindowsDevice::WindowsDevice() {
		
}

void WindowsDevice::fillScreenRect(const int x, const int y, const int w, const int h, const unsigned int color) const {
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);
	RECT rect = { x, y, x + w, y + h };
	HBRUSH brush = CreateSolidBrush(translateColor(color));
	FillRect(device_context, &rect, brush);
	DeleteObject(brush);
	ReleaseDC(console_handle, device_context);
}

int WindowsDevice::getScreenWidth() const {
	return 320;
}

int WindowsDevice::getScreenHeight() const {
	return 240;
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

COLORREF WindowsDevice::translateColor(const unsigned int color) const {
	switch (color) {
	case 0x0000:							// black 
		return RGB(0, 0, 0);
	default:								// yellow
		return RGB(255, 255, 0);
	}
}