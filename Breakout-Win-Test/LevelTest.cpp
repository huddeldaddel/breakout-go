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
		Rectangle* rect = level->getBorderLeftRect();
		Assert::IsTrue(Rectangle{ 0, 0, 5, 240 } == *rect);
		delete rect;

		delete level;
		delete device;
	}

	TEST_METHOD(BorderTop) {
		TestDevice* device = new TestDevice(true);
		Level* level = new Level(device);

		Assert::AreEqual(5, level->getBorderTop());
		Rectangle* rect = level->getBorderTopRect();
		Assert::IsTrue(Rectangle{ 0, 0, 320, 5 } == *rect);
		delete rect;

		delete level;
		delete device;
	}

	TEST_METHOD(BorderRight) {
		TestDevice* device = new TestDevice(true);
		Level* level = new Level(device);

		Assert::AreEqual(5, level->getBorderRight());
		Rectangle* rect = level->getBorderRightRect();
		Assert::IsTrue(Rectangle{ 315, 0, 5, 240 } == *rect);
		delete rect;

		delete level;
		delete device;
	}

};
