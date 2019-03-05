#include "CppUnitTest.h"

#include "../Breakout-Go/Rectangle.h"
#include "../Breakout-Go/Slider.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(SliderTest) {
public:
		
	TEST_METHOD(ConstructToRect) {
		Slider* slider = new Slider(23, 55, 10, 5, 0);
		Rectangle rect = slider->toRect();
			
		Assert::AreEqual(23, rect.positionX);
		Assert::AreEqual(55, rect.positionY);
		Assert::AreEqual(10, rect.width);
		Assert::AreEqual(5, rect.height);

		delete slider;
	}

	TEST_METHOD(ConstructModifyToRect) {
		Slider* slider = new Slider(23, 55, 10, 5, 0);
		slider->setPositionX(42);
		Rectangle rect = slider->toRect();

		Assert::AreEqual(42, rect.positionX);
		Assert::AreEqual(55, rect.positionY);
		Assert::AreEqual(10, rect.width);
		Assert::AreEqual(5, rect.height);

		delete slider;
	}

};
