#include "CollisionCalculator.h"

CollisionCalculator::CollisionCalculator(Ball* b, Device* d, Level* l) : ball{ b }, device{ d }, level{ l } {
}

CollisionCalculator::~CollisionCalculator() {
}
    
int CollisionCalculator::getLeftWallCollisionOverlap() {
	return int(level->getBorderLeft() - (ball->getPositionX() - ball->getRadius()));
}

int CollisionCalculator::getRightWallCollisionOverlap() {
	// (ball->getPositionX() + ball->getRadius() >= (device->getScreenWidth() - level->getBorderRight()))
	return 0;
}
