#include "CollisionCalculator.h"

CollisionCalculator::CollisionCalculator(Ball* b, Device* d, Level* l) : ball{ b }, device{ d }, level{ l } {
}

CollisionCalculator::~CollisionCalculator() {
}
    
float CollisionCalculator::getDistanceToPoint(Line& line, Point* point) {
#ifdef _DEBUG	
	// We use functions from standard library on Windows
	float a = std::fabsf(line.getX1() - point->getX());
	float b = std::fabsf(line.getY1() - point->getY());
	return std::sqrtf(a * a + b * b);
#else			
	// We use functions from arduino library on the Odroid-Go
	float a = abs(line.getX1() - point->getX());
	float b = abs(line.getY1() - point->getY());
	return sqrt(a * a + b * b);
#endif
}

Point* CollisionCalculator::getIntersectionOfLines(Line& line1, Line& line2) {
	float a = ((line2.getX2() - line2.getX1()) * (line1.getY1() - line2.getY1()) - (line2.getY2() - line2.getY1()) * (line1.getX1() - line2.getX1())) / ((line2.getY2() - line2.getY1()) * (line1.getX2() - line1.getX1()) - (line2.getX2() - line2.getX1()) * (line1.getY2() - line1.getY1()));
	float b = ((line1.getX2() - line1.getX1()) * (line1.getY1() - line2.getY1()) - (line1.getY2() - line1.getY1()) * (line1.getX1() - line2.getX1())) / ((line2.getY2() - line2.getY1()) * (line1.getX2() - line1.getX1()) - (line2.getX2() - line2.getX1()) * (line1.getY2() - line1.getY1()));
	if (a >= 0 && a <= 1 && b >= 0 && b <= 1) {
		float intersectionX = line1.getX1() + (a * (line1.getX2() - line1.getX1()));
		float intersectionY = line1.getY1() + (a * (line1.getY2() - line1.getY1()));
		return new Point(intersectionX, intersectionY);
	}
	return nullptr;
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
