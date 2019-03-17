#include "Controller.h"

const int DEFAULT_LIFE_COUNT = 3;
const int DEFAULT_BALL_RADIUS = 3;
const float DEFAULT_BALL_SPEED = 4;
const int DEFAULT_SLIDER_WIDTH = 50;

Controller::Controller(Device* device) : device{ device } {
	renderer = new Renderer(device);

	LevelFactory* levelFactory = new LevelFactory(device);
	level = levelFactory->buildLevel(1);
	delete levelFactory;

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
	for (int i = 0; i < level->getBlocks().size(); i++) {
		renderer->renderBlock(level->getBlocks().at(i));
	}
}

void Controller::updateGame() {
	bool ballStarted = false;
    if(!ball->isMoving() && (device->isButtonAPressed() || device->isButtonBPressed())) {
		startBall();
		ballStarted = true;
    }
  
    renderer->removeBall(ball);
    updateBallPosition(ball->getSpeedX(), ball->getSpeedY());
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

	if (ball->getPositionY() > device->getScreenHeight()) {
		handleDeath();
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
		renderer->removeBall(ball);
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
  slider->setWidth(DEFAULT_SLIDER_WIDTH);
  slider->setHeight(3);
  slider->setSpeed(5.5);
  slider->setPositionX(float(device->getScreenWidth() - level->getBorderLeft() - level->getBorderRight() - slider->getWidth()) / 2); 
  slider->setPositionY(float(device->getScreenHeight() -10));
}

bool compareCollisions(Collision* i, Collision* j) {
	if ((nullptr == i) && (nullptr == j))
		return false;
	if ((nullptr != i) && (nullptr == j))
		return true;
	if ((nullptr == i) && (nullptr != j))
		return false;
	return i->getDistance() < j->getDistance();
}

void Controller::updateBallPosition(float momentumX, float momentumY) {
	CollisionCalculator calculator{ ball, device, level };
	std::vector<Collision*> collisions{ };

	// Walls
	collisions.push_back(calculator.getCollisionWithLeftWall(momentumX, momentumY));
	collisions.push_back(calculator.getCollisionWithTopWall(momentumX, momentumY));
	collisions.push_back(calculator.getCollisionWithRightWall(momentumX, momentumY));

	// Slider
	Rectangle* sliderRect = slider->toRect();
	collisions.push_back(calculator.getCollision(*sliderRect, momentumX, momentumY));
	delete sliderRect;

	std::sort(collisions.begin(), collisions.end(), compareCollisions);
	Collision* collision = collisions.at(0);
	if (nullptr != collision) {
		float distanceX = momentumX - collision->getRemainingMomentumX();
		float distanceY = momentumY - collision->getRemainingMomentumY();
		ball->setPositionX(ball->getPositionX() + distanceX);
		ball->setPositionY(ball->getPositionY() + distanceY);

		Direction direction = collision->getDirection();
		if (Direction::LEFT == direction || Direction::RIGHT == direction) {
			ball->invertMovementX();
			updateBallPosition(0 - collision->getRemainingMomentumX(), collision->getRemainingMomentumY());
		} else {
			ball->invertMovementY();
			updateBallPosition(collision->getRemainingMomentumX(), 0 - collision->getRemainingMomentumY());
		}
		
	} else {
		ball->setPositionX(ball->getPositionX() + momentumX);
		ball->setPositionY(ball->getPositionY() + momentumY);
	}

	for (int i = 0; i < collisions.size(); i++)
		if (nullptr != collisions.at(i))
			delete collisions.at(i);
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
