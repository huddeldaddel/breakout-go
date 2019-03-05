#include "CppUnitTest.h"
#include <vector>

#include "../Breakout-Go/Rectangle.h"
#include "../Breakout-Go/Renderer.h"
#include "../Breakout-Go/Slider.h"

#include "DrawOperationRectangle.h"
#include "TestDevice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(RendererTest) {
public:

	TEST_METHOD(ClearScreen) {
		TestDevice* device = new TestDevice(true);
		Renderer* renderer = new Renderer(device);
		
		renderer->clearScreen();

		std::vector<DrawOperationRectangle> drawOpsRect = device->getDrawnRectangles();
		Assert::AreEqual(1, int(drawOpsRect.size()));
		Assert::AreEqual(0, drawOpsRect.at(0).x);
		Assert::AreEqual(0, drawOpsRect.at(0).y);
		Assert::AreEqual(320, drawOpsRect.at(0).w);
		Assert::AreEqual(240, drawOpsRect.at(0).h);
		Assert::AreEqual(0, int(drawOpsRect.at(0).color));

		delete renderer;
		delete device;
	}

	TEST_METHOD(RemoveSlider) {
		TestDevice* device = new TestDevice(true);
		Slider* slider = new Slider(23, 55, 10, 5, 0);
		Renderer* renderer = new Renderer(device);
		Rectangle sliderRect = slider->toRect();
	
		renderer->removeSlider(slider);

		std::vector<DrawOperationRectangle> drawOpsRect = device->getDrawnRectangles();
		Assert::AreEqual(1, int(drawOpsRect.size()));

		Assert::AreEqual(sliderRect.positionX, drawOpsRect.at(0).x);
		Assert::AreEqual(sliderRect.positionY, drawOpsRect.at(0).y);
		Assert::AreEqual(sliderRect.width, drawOpsRect.at(0).w);
		Assert::AreEqual(sliderRect.height, drawOpsRect.at(0).h);
		Assert::AreEqual(0, int(drawOpsRect.at(0).color));

		delete slider;
		delete renderer;
		delete device;
	}

	TEST_METHOD(RenderSlider) {
		TestDevice* device = new TestDevice(true);
		Slider* slider = new Slider(23, 55, 10, 5, 0);
		Renderer* renderer = new Renderer(device);
		Rectangle sliderRect = slider->toRect();

		renderer->renderSlider(slider);

		std::vector<DrawOperationRectangle> drawOpsRect = device->getDrawnRectangles();
		Assert::AreEqual(1, int(drawOpsRect.size()));

		Assert::AreEqual(sliderRect.positionX, drawOpsRect.at(0).x);
		Assert::AreEqual(sliderRect.positionY, drawOpsRect.at(0).y);
		Assert::AreEqual(sliderRect.width, drawOpsRect.at(0).w);
		Assert::AreEqual(sliderRect.height, drawOpsRect.at(0).h);
		Assert::AreEqual(0x7BEF, int(drawOpsRect.at(0).color));

		delete slider;
		delete renderer;
		delete device;
	}
};
