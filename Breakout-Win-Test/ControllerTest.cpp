#include "CppUnitTest.h"

#include "../Breakout-Go/Controller.h"
#include "../Breakout-Go/Level.h"

#include "TestDevice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(ControllerTest) {
public:

	TEST_METHOD(ConstructToRect) {
		Device* device = new TestDevice(false);
		Controller* controller = new Controller(device);
		
		Assert::AreEqual(140, int(controller->getSlider()->getPositionX()));
		Assert::AreEqual(230, int(controller->getSlider()->getPositionY()));
		Assert::AreEqual(30, int(controller->getSlider()->getWidth()));
		Assert::AreEqual(3, int(controller->getSlider()->getHeight()));

		delete controller;
		delete device;
	}

};
