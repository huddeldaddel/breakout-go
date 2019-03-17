#include "CppUnitTest.h"

#include "../Breakout-Go/Controller.h"
#include "../Breakout-Go/Level.h"

#include "TestDevice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(ControllerTest) {
public:

	TEST_METHOD(GameStart) {
		Device* device = new TestDevice(false);
		Controller* controller = new Controller(device);
		
		controller->startNewGame();
		
		Assert::AreEqual(125, int(controller->getSlider()->getPositionX()));
		Assert::AreEqual(230, int(controller->getSlider()->getPositionY()));
		Assert::AreEqual(50, int(controller->getSlider()->getWidth()));
		Assert::AreEqual(3, int(controller->getSlider()->getHeight()));

		Assert::AreEqual(150, int(controller->getBall()->getPositionX()));
		Assert::AreEqual(227, int(controller->getBall()->getPositionY()));

		delete controller;
		delete device;
	}

};
