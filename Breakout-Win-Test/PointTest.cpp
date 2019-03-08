#include "CppUnitTest.h"

#include "../Breakout-Go/Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(PointTest) {
public:

	TEST_METHOD(ComparisonOperators) {
		Point p1{ 0, 1 };
		Point p2{ 0, 1 };
		Point p3{ 1, 2 };

		Assert::IsTrue(p1 == p1);
		Assert::IsTrue(p1 == p2);
		Assert::IsTrue(p2 == p1);
		Assert::IsFalse(p1 == p3);
		Assert::IsFalse(p3 == p1);

		Assert::IsFalse(p1 != p1);
		Assert::IsFalse(p1 != p2);
		Assert::IsFalse(p2 != p1);
		Assert::IsTrue(p1 != p3);
		Assert::IsTrue(p3 != p1);
	}

};
