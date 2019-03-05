#include "CppUnitTest.h"
#include <vector>

#include "../Breakout-Go/Rectangle.h"
#include "../Breakout-Go/Renderer.h"
#include "../Breakout-Go/Slider.h"

#include "DrawOperationRectangle.h"
#include "TestDevice.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BreakoutWinTest {

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

	};
}