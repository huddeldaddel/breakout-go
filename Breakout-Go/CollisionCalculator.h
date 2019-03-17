#ifndef _COLLISION_CALCULATOR_
#define _COLLISION_CALCULATOR_

#ifndef _DEBUG
	// On the Odroid we need that import for various mathematical routines
	#include <odroid_go.h>
#endif

#include <vector>

#include "Ball.h"
#include "Device.h"
#include "Level.h"
#include "Line.h"
#include "Point.h"
#include "Rectangle.h"

enum class Direction { LEFT, RIGHT, UP, DOWN };

class Collision {
private:	
	Direction direction;
	float distance;
	Point* point;
	float remainingMomentumX;
	float remainingMomentumY;
public:
	Collision(Direction direction, float distance, Point* point, float remainingMomentumX, float remainingMomentumY);
	~Collision();

	Direction getDirection() const;
	float getDistance() const;
	Point* getPoint() const;
	float getRemainingMomentumX() const;
	float getRemainingMomentumY() const;
};

class CollisionCalculator {
  private:
    Ball* ball;
    Device* device;
    Level* level;
  public:
    CollisionCalculator(Ball* b, Device* d, Level* l);
    ~CollisionCalculator();

	/* Returns 4 lines that outline the movement of the ball. These lines are:
	 *
	 * 0: oldPosition.bottom -> newPosition.bottom
	 * 1: oldPosition.top -> newPosition.top
	 * 2: oldPosition.left -> newPosition.left
	 * 3: oldPosition.right -> newPosition.right
	 */
	std::vector<Line> getBallMovementOutlines(float momentumX, float momentumY);

	float getDistanceToPoint(Line& line, Point* point) const;
	Point* getIntersectionOfLines(Line& line1, Line& line2) const;
	Collision* getNearestCollision(Line& line, std::vector<Line> outlines, float momentumX, float momentumY, bool isHorizontal);
	Collision* getCollision(Rectangle& rectangle, float momentumX, float momentumY);
	Collision* getCollisionWithLeftWall(float momentumX, float momentumY);
	Collision* getCollisionWithRightWall(float momentumX, float momentumY);
	Collision* getCollisionWithTopWall(float momentumX, float momentumY);

    int getLeftWallCollisionOverlap(); 
    int getRightWallCollisionOverlap(); 
	int getTopWallCollisionOverlap();

};

#endif
