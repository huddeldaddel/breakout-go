#include "CppUnitTest.h"

#include "../Breakout-Go/Ball.h"
#include "../Breakout-Go/CollisionCalculator.h"
#include "../Breakout-Go/Device.h"
#include "../Breakout-Go/Level.h"
#include "../Breakout-Go/Line.h"

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

	TEST_METHOD(getIntersectionOfLines) {
		Ball* ball = new Ball(0, 0, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);

		Line leftBorder{ 4, 0, 4, 239 };
		Line ballVector{ 8, 20, 2, 20 };

		Point* intersection = calc->getIntersectionOfLines(leftBorder, ballVector);
		Assert::IsNotNull(intersection);
		Assert::AreEqual(4, int(intersection->getX()));
		Assert::AreEqual(20, int(intersection->getY()));
		delete intersection;

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getDistanceToPoint1) {
		Ball* ball = new Ball(0, 0, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);
		Line line{ 0, 0, 10, 10 };
		Point* intersection = new Point(4, 4);
		
		float distance = calc->getDistanceToPoint(line, intersection);
		Assert::AreEqual(5.65f, distance, 0.01f);
		
		delete intersection;
		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getDistanceToPoint2) {
		Ball* ball = new Ball(0, 0, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);
		Line line{ 10, 10, 0, 0 };
		Point* intersection = new Point(6, 6);

		float distance = calc->getDistanceToPoint(line, intersection);
		Assert::AreEqual(5.65f, distance, 0.01f);

		delete intersection;
		delete calc;
		delete level;
		delete device;
		delete ball;
	}

	TEST_METHOD(getBallMovementOutlines) {
		Ball* ball = new Ball(20, 20, 3);
		Device* device = new TestDevice(false);
		Level* level = new Level(device);
		CollisionCalculator* calc = new CollisionCalculator(ball, device, level);
		
		std::vector<Line> outlines = calc->getBallMovementOutlines(5.0f, 5.0f);
		Assert::AreEqual(4, int(outlines.size()));
		Assert::IsTrue(Line{ 20, 23, 25, 28 } == outlines.at(0));
		Assert::IsTrue(Line{ 20, 17, 25, 22 } == outlines.at(1));
		Assert::IsTrue(Line{ 17, 20, 22, 25 } == outlines.at(2));
		Assert::IsTrue(Line{ 23, 20, 28, 25 } == outlines.at(3));

		delete calc;
		delete level;
		delete device;
		delete ball;
	}

};
