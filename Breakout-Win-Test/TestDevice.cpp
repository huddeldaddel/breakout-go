#include "TestDevice.h"

TestDevice::TestDevice(const bool storeDrawOps) : storeDrawOperations{ storeDrawOps } {
}

TestDevice::~TestDevice() {
}

void TestDevice::fillScreenRect(const int x, const int y, const int w, const int h, const unsigned int color) {
	if (storeDrawOperations) {
		DrawOperationRectangle rectangle{ x, y, w, h, color };
		drawnRectangles.push_back(rectangle);
	}
}

void TestDevice::fillScreenCircle(const int x, const int y, const int r, const unsigned int color) {
	if (storeDrawOperations) {
		DrawOperationCircle circle{ x, y, r, color };
		drawnCircles.push_back(circle);
	}
}

int TestDevice::getScreenWidth() const {
	return 320;
}

int TestDevice::getScreenHeight() const {
	return 240;
}

bool TestDevice::isButtonAPressed() const {
	return false;
}

bool TestDevice::isButtonBPressed() const {
	return false;
}

bool TestDevice::isDirectionDownPressed() const {
	return false;
}

bool TestDevice::isDirectionLeftPressed() const {
	return false;
}

bool TestDevice::isDirectionUpPressed() const {
	return false;
}

bool TestDevice::isDirectionRightPressed() const {
	return false;
}

void TestDevice::sleep(const int millis) const {

}

std::vector<DrawOperationCircle> TestDevice::getDrawnCircles() const {
	return drawnCircles;
}

std::vector<DrawOperationRectangle> TestDevice::getDrawnRectangles() const {
	return drawnRectangles;
}