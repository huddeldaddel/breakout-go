#include "CppUnitTest.h"

#include "../Breakout-Go/Level.h"
#include "../Breakout-Go/Rectangle.h"
#include "../Breakout-Go/Slider.h"

#include "TestDevice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(LevelTest) {
public:

	TEST_METHOD(BorderLeft) {
		TestDevice* device = new TestDevice(true);
		Level* level = new Level(device);

		Assert::AreEqual(5, level->getBorderLeft());
		Rectangle rect = level->getBorderLeftRect();
		Assert::AreEqual(0, rect.positionX);
		Assert::AreEqual(0, rect.positionY);
		Assert::AreEqual(5, rect.width);
		Assert::AreEqual(240, rect.height);

		delete level;
		delete device;
	}

	TEST_METHOD(BorderTop) {
		TestDevice* device = new TestDevice(true);
		Level* level = new Level(device);

		Assert::AreEqual(5, level->getBorderTop());
		Rectangle rect = level->getBorderTopRect();
		Assert::AreEqual(0, rect.positionX);
		Assert::AreEqual(0, rect.positionY);
		Assert::AreEqual(320, rect.width);
		Assert::AreEqual(5, rect.height);

		delete level;
		delete device;
	}

	TEST_METHOD(BorderRight) {
		TestDevice* device = new TestDevice(true);
		Level* level = new Level(device);

		Assert::AreEqual(5, level->getBorderRight());
		Rectangle rect = level->getBorderRightRect();
		Assert::AreEqual(315, rect.positionX);
		Assert::AreEqual(0, rect.positionY);
		Assert::AreEqual(5, rect.width);
		Assert::AreEqual(240, rect.height);

		delete level;
		delete device;
	}

};
