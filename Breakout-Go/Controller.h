#ifndef _CONTROLLER_
#define _CONTROLLER_

#include <algorithm>

#include "Ball.h"
#include "CollisionCalculator.h"
#include "Device.h"
#include "Level.h"
#include "MusicPlayer.h"
#include "Renderer.h"
#include "Slider.h"

class Controller {
private:
	Ball* ball;
	Device* device;
	Level* level;
	MusicPlayer* musicPlayer;
	Slider* slider;
	Renderer* renderer;

	bool gameOver;
	int lives;
	long score;

	void handleDeath();
	void handleWon();
	bool isSliderMoving();
	void resetBall();
	void resetSlider();
	void startBall();
	void updateBallPosition(float momentumX, float momentumY);
	void updateBallPositionOnSlider();
	void updateSliderPosition();
public:
	Controller(Device* device, MusicPlayer* mPlayer);
	~Controller();

	Ball* getBall();
	int getLives() const;
	Slider* getSlider();
	bool isGameOver() const;

	void startNewGame();
	void updateGame();
};

#endif
