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

	TEST_METHOD(getRightWallCollisionOverlapTouched) {
		Ball* ball = new Ball(311, 0, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Assert::AreEqual(0, calc->getRightWallCollisionOverlap());

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getRightWallCollisionOverlapNotTouched) {
		Ball* ball = new Ball(310, 0, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Assert::AreEqual(-1, calc->getRightWallCollisionOverlap());

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getRightWallCollisionOverlapFullyMerged) {
		Ball* ball = new Ball(319, 0, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Assert::AreEqual(8, calc->getRightWallCollisionOverlap());

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getTopWallCollisionOverlapTouched) {
		Ball* ball = new Ball(0, 8, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Assert::AreEqual(0, calc->getTopWallCollisionOverlap());

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getTopWallCollisionOverlapNotTouched) {
		Ball* ball = new Ball(0, 9, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Assert::AreEqual(-1, calc->getTopWallCollisionOverlap());

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getTopWallCollisionOverlapFullyMerged) {
		Ball* ball = new Ball(0, 0, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Assert::AreEqual(8, calc->getTopWallCollisionOverlap());

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

};
