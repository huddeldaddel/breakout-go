#include "CppUnitTest.h"

#include "../Breakout-Go/Ball.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(BallTest) {
public:

	TEST_METHOD(InvertMovementX) {
		Ball ball{ 0, 1, 3 };
		ball.setSpeedX(5);
		ball.setSpeedY(5);
		ball.invertMovementX();

		Assert::AreEqual(0.0f, ball.getPositionX());
		Assert::AreEqual(1.0f, ball.getPositionY());
		Assert::AreEqual(-5.0f, ball.getSpeedX());
		Assert::AreEqual(5.0f, ball.getSpeedY());
	}

	TEST_METHOD(InvertMovementY) {
		Ball ball{ 0, 1, 3 };
		ball.setSpeedX(5);
		ball.setSpeedY(5);
		ball.invertMovementY();

		Assert::AreEqual(0.0f, ball.getPositionX());
		Assert::AreEqual(1.0f, ball.getPositionY());
		Assert::AreEqual(5.0f, ball.getSpeedX());
		Assert::AreEqual(-5.0f, ball.getSpeedY());
	}

};
