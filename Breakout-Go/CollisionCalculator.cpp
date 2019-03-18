#include "CollisionCalculator.h"

Collision::Collision(Direction direction, float distance, Point* point, float mx, float my) : 
	rectangle{ nullptr }, direction{ direction }, distance{ distance }, point{ point }, remainingMomentumX{ mx },
	remainingMomentumY{ my } {
}

Collision::~Collision() {
	if (nullptr != point)
		delete point;
}

Rectangle* Collision::getRectangle() const {
	return rectangle;
}

void Collision::setRectangle(Rectangle* r) {
	rectangle = r;
}

Direction Collision::getDirection() const {
	return direction;
}

float Collision::getDistance() const {
	return distance;
}

Point* Collision::getPoint() const {
	return point;
}

float Collision::getRemainingMomentumX() const {
	return remainingMomentumX;
}

float Collision::getRemainingMomentumY() const {
	return remainingMomentumY;
}

CollisionCalculator::CollisionCalculator(Ball* b, Device* d, Level* l) : ball{ b }, device{ d }, level{ l } {
}

CollisionCalculator::~CollisionCalculator() {
}

std::vector<Line> CollisionCalculator::getBallMovementOutlines(float momentumX, float momentumY) {
	std::vector<Line> result{ };
	result.push_back(Line{ ball->getPositionX(), ball->getPositionY() + ball->getRadius(), ball->getPositionX() + momentumX, ball->getPositionY() + ball->getRadius() + momentumY });
	result.push_back(Line{ ball->getPositionX(), ball->getPositionY() - ball->getRadius(), ball->getPositionX() + momentumX, ball->getPositionY() - ball->getRadius() + momentumY });
	result.push_back(Line{ ball->getPositionX() - ball->getRadius(), ball->getPositionY(), ball->getPositionX() - ball->getRadius() + momentumX, ball->getPositionY() + momentumY });
	result.push_back(Line{ ball->getPositionX() + ball->getRadius(), ball->getPositionY(), ball->getPositionX() + ball->getRadius() + momentumX, ball->getPositionY() + momentumY });
	return result;
}
    
float CollisionCalculator::getDistanceToPoint(Line& line, Point* point) const {
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

Point* CollisionCalculator::getIntersectionOfLines(Line& line1, Line& line2) const {
	float a = ((line2.getX2() - line2.getX1()) * (line1.getY1() - line2.getY1()) - (line2.getY2() - line2.getY1()) * (line1.getX1() - line2.getX1())) / ((line2.getY2() - line2.getY1()) * (line1.getX2() - line1.getX1()) - (line2.getX2() - line2.getX1()) * (line1.getY2() - line1.getY1()));
	float b = ((line1.getX2() - line1.getX1()) * (line1.getY1() - line2.getY1()) - (line1.getY2() - line1.getY1()) * (line1.getX1() - line2.getX1())) / ((line2.getY2() - line2.getY1()) * (line1.getX2() - line1.getX1()) - (line2.getX2() - line2.getX1()) * (line1.getY2() - line1.getY1()));
	if (a >= 0 && a <= 1 && b >= 0 && b <= 1) {
		float intersectionX = line1.getX1() + (a * (line1.getX2() - line1.getX1()));
		float intersectionY = line1.getY1() + (a * (line1.getY2() - line1.getY1()));
		return new Point(intersectionX, intersectionY);
	}
	return nullptr;
}

Collision* CollisionCalculator:: getCollision(Rectangle* rectangle, float momentumX, float momentumY) {
	std::vector<Line> outlines = getBallMovementOutlines(momentumX, momentumY);

	Line* horzRectLine = momentumY > 0 ? rectangle->getTopBorder() : rectangle->getBottomBorder();
	Collision* horzCollision = getNearestCollision(*horzRectLine, outlines, momentumX, momentumY, true);
	delete horzRectLine;

	Line* vertRectLine = momentumX > 0 ? rectangle->getLeftBorder() : rectangle->getRightBorder();
	Collision* vertCollision = getNearestCollision(*vertRectLine, outlines, momentumX, momentumY, false);
	delete vertRectLine;

	if ((nullptr == horzCollision) && (nullptr == vertCollision))
		return nullptr;

	if ((nullptr != horzCollision) && (nullptr == vertCollision)) {
		horzCollision->setRectangle(rectangle);
		return horzCollision;
	}

	if ((nullptr == horzCollision) && (nullptr != vertCollision)) {
		vertCollision->setRectangle(rectangle);
		return vertCollision;
	}

	horzCollision->setRectangle(rectangle);
	vertCollision->setRectangle(rectangle);

	if (horzCollision->getDistance() <= vertCollision->getDistance()) {
		delete vertCollision;
		return horzCollision;
	} 
	
	delete horzCollision;
	return vertCollision;
}

Collision* CollisionCalculator::getCollisionWithLeftWall(float momentumX, float momentumY) {
	if (momentumX >= 0)
		return nullptr;

	float x = float(level->getBorderLeft());
	Line* vertRectLine = new Line(x, 0, x, float(device->getScreenHeight()));
	std::vector<Line> outlines = getBallMovementOutlines(momentumX, momentumY);
	Collision* result = getNearestCollision(*vertRectLine, outlines, momentumX, momentumY, false);
	delete vertRectLine;

	return result;
}

Collision* CollisionCalculator::getCollisionWithRightWall(float momentumX, float momentumY) {
	if (momentumX <= 0)
		return nullptr;

	float x = float(device->getScreenWidth() - level->getBorderRight());
	Line* vertRectLine = new Line(x, 0, x, float(device->getScreenHeight()));
	std::vector<Line> outlines = getBallMovementOutlines(momentumX, momentumY);
	Collision* result = getNearestCollision(*vertRectLine, outlines, momentumX, momentumY, false);
	delete vertRectLine;

	return result;
}

Collision* CollisionCalculator::getCollisionWithTopWall(float momentumX, float momentumY) {
	if (momentumY >= 0)
		return nullptr;

	float y = float(level->getBorderTop());
	Line* vertRectLine = new Line(0, y, float(device->getScreenWidth()), y);
	std::vector<Line> outlines = getBallMovementOutlines(momentumX, momentumY);
	Collision* result = getNearestCollision(*vertRectLine, outlines, momentumX, momentumY, true);
	delete vertRectLine;

	return result;
}

Collision* CollisionCalculator::getNearestCollision(Line& line, std::vector<Line> outlines, float momentumX, float momentumY, bool isHorizontal) {
	bool found = false;
	float shortestDistance = 1000.0f;
	Point* point = nullptr;
	float remainingMomentumX = 0;
	float remainingMomentumY = 0;

	for (int i = 0; i < outlines.size(); i++) {
		Line outline = outlines.at(i);

		Point* intersection = getIntersectionOfLines(outline, line);
		if (nullptr != intersection) {
			found = true;
			float distance = getDistanceToPoint(outline, intersection);
			if (distance < shortestDistance) {
				if (nullptr != point)
					delete point;
				point = intersection;
				shortestDistance = distance;
				remainingMomentumX = momentumX - (intersection->getX() - outline.getX1());
				remainingMomentumY = momentumY - (intersection->getY() - outline.getY1());
			} else {
				delete intersection;
			}
		}
	}

	Direction direction;
	if (isHorizontal) {
		direction = momentumY > 0 ? Direction::DOWN : Direction::UP;
	} else {
		direction = momentumX > 0 ? Direction::RIGHT : Direction::LEFT;
	}

	return found ? new Collision(direction, shortestDistance, point, remainingMomentumX, remainingMomentumY) : nullptr;
}