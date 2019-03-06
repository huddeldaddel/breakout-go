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

enum class Collision { NONE, FROM_LEFT, FROM_RIGHT, FROM_TOP, FROM_BOTTOM };

class CollisionCalculator {
  private:
    Ball* ball;
    Device* device;
    Level* level;
  public:
    CollisionCalculator(Ball* b, Device* d, Level* l);
    ~CollisionCalculator();
    
	float getDistanceToPoint(Line& line, Point* point);
	Point* getIntersectionOfLines(Line& line1, Line& line2);

    int getLeftWallCollisionOverlap(); 
    int getRightWallCollisionOverlap(); 
	int getTopWallCollisionOverlap();

};

#endif
