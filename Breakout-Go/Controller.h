#ifndef _CONTROLLER_
#define _CONTROLLER_

#include <algorithm>

#include "Ball.h"
#include "CollisionCalculator.h"
#include "Device.h"
#include "Level.h"
#include "Renderer.h"
#include "Slider.h"

class Controller {
	private:
		Ball* ball;
		Device* device;
		Level* level;
		Slider* slider;
		Renderer* renderer;

		int lives;
		bool gameOver;

		void handleDeath();
		bool isSliderMoving();

		void resetBall();
		void resetSlider();

		void startBall();

		void updateBallPosition(float momentumX, float momentumY);

		void updateBallPositionOnSlider();
		void updateSliderPosition();
	public:
		Controller(Device* device);
		~Controller();

		Ball* getBall();
		int getLives() const;
		Slider* getSlider();
		bool isGameOver() const;

		void startNewGame();
    void updateGame();
};

#endif
