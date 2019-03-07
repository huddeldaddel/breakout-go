#include "CppUnitTest.h"

#include "../Breakout-Go/Line.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(LineTest) {
public:

	TEST_METHOD(ComparisonOperators) {
		Line l1{ 0, 1, 2, 3 };
		Line l2{ 0, 1, 2, 3 };
		Line l3{ 1, 2, 3, 4 };

		Assert::IsTrue(l1 == l1);
		Assert::IsTrue(l1 == l2);
		Assert::IsTrue(l2 == l1);
		Assert::IsFalse(l1 == l3);
		Assert::IsFalse(l3 == l1);

		Assert::IsFalse(l1 != l1);
		Assert::IsFalse(l1 != l2);
		Assert::IsFalse(l2 != l1);
		Assert::IsTrue(l1 != l3);
		Assert::IsTrue(l3 != l1);
	}

};
