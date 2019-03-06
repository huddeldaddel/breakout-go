#include "CppUnitTest.h"

#include "../Breakout-Go/Ball.h"
#include "../Breakout-Go/CollisionCalculator.h"
#include "../Breakout-Go/Device.h"
#include "../Breakout-Go/Level.h"

#include "TestDevice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(CollisionCalculatorTest) {
public:

	TEST_METHOD(getLeftWallCollisionOverlapTouched) {
		Ball* ball = new Ball(8, 0, 3); 
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Assert::AreEqual(0, calc->getLeftWallCollisionOverlap());

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getLeftWallCollisionOverlapNotTouched) {
		Ball* ball = new Ball(9, 0, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Assert::AreEqual(-1, calc->getLeftWallCollisionOverlap());

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getLeftWallCollisionOverlapFullyMerged) {
		Ball* ball = new Ball(0, 0, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Assert::AreEqual(8, calc->getLeftWallCollisionOverlap());

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

};
