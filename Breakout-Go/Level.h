#ifndef _LEVEL_
#define _LEVEL_

#include "Device.h"
#include "Rectangle.h"

class Level {
private:
	Device* device;
	int number;
	int borderLeft;
	int borderTop;
	int borderRight;
public:
	Level(Device* d);
    
	int getNumber();
	int getBorderLeft();
	int getBorderTop();
	int getBorderRight();

	Rectangle getBorderLeftRect();
	Rectangle getBorderTopRect();
	Rectangle getBorderRightRect();
};

#endif
