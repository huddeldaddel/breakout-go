#include "Controller.h"

const int DEFAULT_LIFE_COUNT = 3;
const int DEFAULT_BALL_RADIUS = 3;
const float DEFAULT_BALL_SPEED = 4;

Controller::Controller(Device* device) : device{ device } {
	renderer = new Renderer(device);
	level = new Level(device);
	slider = new Slider(0, 0, 0, 0, 0);
	ball = new Ball(0, 0, DEFAULT_BALL_RADIUS);

	lives = 0;
	gameOver = false;
}

Controller::~Controller() {
	delete ball;
	delete slider;
	delete level;
	delete renderer;
}

Ball* Controller::getBall() {
	return ball;
}

int Controller::getLives() const {
	return lives;
}

Slider* Controller::getSlider() {
	return slider;
}

bool Controller::isGameOver() const {
	return gameOver;
}

void Controller::startNewGame() {
	lives = DEFAULT_LIFE_COUNT;
	gameOver = false;

	resetSlider();
	updateBallPositionOnSlider();

	renderer->clearScreen();
	renderer->renderBorders(level);
	renderer->renderSlider(slider);
	renderer->renderBall(ball);
}

void Controller::updateGame() {
	bool ballStarted = false;
    if(!ball->isMoving() && (device->isButtonAPressed() || device->isButtonBPressed())) {
		startBall();
		ballStarted = true;
    }
  
    renderer->removeBall(ball);
    updateBallPosition();
    renderer->renderBall(ball);
  
    if(isSliderMoving()) {
		renderer->removeSlider(slider);
		updateSliderPosition();
		if(!ball->isMoving()) {
			renderer->removeBall(ball);
			updateBallPositionOnSlider();
			renderer->renderBall(ball);
		}
    }
    
	if (ballStarted || isSliderMoving()) {
		renderer->renderSlider(slider);
	}
}

void Controller::startBall() {
	ball->setMoving(true);
	ball->setSpeedX(DEFAULT_BALL_SPEED);
	if(device->isButtonBPressed()) {
		ball->setSpeedX(ball->getSpeedX() * -1);
	}
	ball->setSpeedY(DEFAULT_BALL_SPEED * -1);
}

void Controller::handleDeath() {
	lives -= 1;
	if (lives > 0) {
		renderer->removeSlider(slider);

		resetSlider();
		resetBall();
		updateBallPositionOnSlider();

		renderer->renderSlider(slider);
		renderer->renderBall(ball);
	} else {
		gameOver = true;
	}
}

bool Controller::isSliderMoving() {
	return device->isDirectionLeftPressed() || device->isDirectionRightPressed();
}

void Controller::resetBall() {
	updateBallPositionOnSlider();
	ball->setMoving(false);
	ball->setSpeedX(0);
	ball->setSpeedY(0);
	ball->setRadius(DEFAULT_BALL_RADIUS);
}

void Controller::resetSlider() {
  slider->setWidth(30);
  slider->setHeight(3);
  slider->setSpeed(5.5);
  slider->setPositionX(float(device->getScreenWidth() - level->getBorderLeft() - level->getBorderRight() - slider->getWidth()) / 2); 
  slider->setPositionY(float(device->getScreenHeight() -10));
}

void Controller::updateBallPosition() {
	ball->setPositionX(ball->getPositionX() + ball->getSpeedX());
	ball->setPositionY(ball->getPositionY() + ball->getSpeedY());

	CollisionCalculator calculator{ ball, device, level };
	if (calculator.getRightWallCollisionOverlap() >= 0) {
		ball->setPositionX(ball->getPositionX() - 2 * calculator.getRightWallCollisionOverlap());
		ball->setSpeedX(ball->getSpeedX() * -1);
	} else if(calculator.getLeftWallCollisionOverlap() >= 0) {
		ball->setPositionX(ball->getPositionX() + 2 * calculator.getLeftWallCollisionOverlap());
		ball->setSpeedX(ball->getSpeedX() * -1);
	}

	if ((ball->getSpeedY() < 0) && (ball->getPositionY() - ball->getRadius() <= level->getBorderTop())) {                     
		// bounce off top
		ball->setPositionY(ball->getPositionY() + 2 * (level->getBorderTop() - (ball->getPositionY() - ball->getRadius())));
		ball->setSpeedY(ball->getSpeedY() * -1);
	} else if ((ball->getSpeedY() > 0) &&                                                              
		(ball->getPositionY() + ball->getRadius() >= slider->getPositionY() + slider->getHeight()) &&
		(ball->getPositionY() - ball->getSpeedY() + ball->getRadius() < slider->getPositionY() + slider->getHeight())) {
		const float interceptX = (ball->getPositionX() - ball->getSpeedX()) + ball->getSpeedX() * ((slider->getPositionY() - ball->getRadius() - ball->getPositionY()) / ball->getSpeedY());
		if ((interceptX >= slider->getPositionX()) && (interceptX <= slider->getPositionX() + slider->getWidth())) {
			// bounce off slider 
			ball->setPositionY(ball->getPositionY() - 2 * ((ball->getPositionY() + ball->getRadius()) - slider->getPositionY()));
			ball->setSpeedY(ball->getSpeedY() * -1);
		}
		
		/*
		else if ((interceptX < slider->getPositionX()) && (interceptX + ball->getRadius() >= slider->getPositionX())) {
			positionY -= 2 * ((positionY + ball->getRadius()) - slider->getPositionY());
			speedY *= -1;
			speedX = abs(speedX) * -1;
		} else if ((interceptX > slider->getPositionX() + slider->getWidth()) && (interceptX - ball->getRadius() - ball->getRadius()  <= slider->getPositionX() + slider->getWidth())) {
			positionY -= 2 * ((positionY + ball->getRadius()) - slider->getPositionY());
			speedY *= -1;
			speedX = abs(speedX);
		}
		*/
	}

	if (ball->getPositionY() > device->getScreenHeight()) {
		handleDeath();
	}
}

void Controller::updateBallPositionOnSlider() {
	ball->setPositionX(slider->getPositionX() + slider->getWidth() / 2);
	ball->setPositionY(slider->getPositionY() - ball->getRadius());
}

void Controller::updateSliderPosition() {
	if (device->isDirectionLeftPressed()) {
		slider->setPositionX(slider->getPositionX() - slider->getSpeed());
	} else if (device->isDirectionRightPressed()) {
		slider->setPositionX(slider->getPositionX() + slider->getSpeed());
	}
		
	if (slider->getPositionX() < float(level->getBorderLeft())) {
		slider->setPositionX(float(level->getBorderLeft()));
	} else if (slider->getPositionX() > float(device->getScreenWidth() - level->getBorderRight() - slider->getWidth())) {
		slider->setPositionX(float(device->getScreenWidth() - level->getBorderRight() - slider->getWidth()));
	}
}
