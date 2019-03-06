#include "CollisionCalculator.h"

CollisionCalculator::CollisionCalculator(Ball* b, Device* d, Level* l) : ball{ b }, device{ d }, level{ l } {
}

CollisionCalculator::~CollisionCalculator() {
}
    
int CollisionCalculator::getLeftWallCollisionOverlap() {
	return int(level->getBorderLeft() - (ball->getPositionX() - ball->getRadius()));
}

int CollisionCalculator::getRightWallCollisionOverlap() {
	const int firstPixelOfWall = device->getScreenWidth() - level->getBorderRight();
	const float ballPlusRadius = ball->getPositionX() + ball->getRadius();
	return -1 * int(firstPixelOfWall -1 - ballPlusRadius);
}

int CollisionCalculator::getTopWallCollisionOverlap() {
	return int(level->getBorderTop() - (ball->getPositionY() - ball->getRadius()));
}