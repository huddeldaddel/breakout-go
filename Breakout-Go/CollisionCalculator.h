#ifndef _COLLISION_CALCULATOR_
#define _COLLISION_CALCULATOR_

#include "Ball.h"
#include "Device.h"
#include "Level.h"

class CollisionCalculator {
  private:
    Ball* ball;
    Device* device;
    Level* level;
  public:
    CollisionCalculator(Ball* b, Device* d, Level* l);
    ~CollisionCalculator();
    
    int getLeftWallCollisionOverlap(); 
    int getRightWallCollisionOverlap(); 
	int getTopWallCollisionOverlap();
};

#endif
