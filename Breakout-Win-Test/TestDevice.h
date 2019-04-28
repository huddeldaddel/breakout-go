#pragma once

#include <iostream>
#include <vector>

#include "DrawOperationCircle.h"
#include "DrawOperationRectangle.h"
#include "../Breakout-Go/Device.h"

class TestDevice : public Device {
private:
	bool storeDrawOperations;
	std::vector<DrawOperationCircle> drawnCircles;
	std::vector<DrawOperationRectangle> drawnRectangles;
public:
	TestDevice(const bool storeDrawOps);
	~TestDevice();

	void beep(const double frequency) const;

	void drawScreenRect(const int x, const int y, const int w, const int h, const unsigned int color);
	void fillScreenRect(const int x, const int y, const int w, const int h, const unsigned int color);
	void fillScreenCircle(const int x, const int y, const int r, const unsigned int color);

	std::vector<DrawOperationCircle> getDrawnCircles() const;
	std::vector<DrawOperationRectangle> getDrawnRectangles() const;

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
};
