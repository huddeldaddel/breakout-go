#ifndef _LEVEL_
#define _LEVEL_

#include <vector>

#include "Block.h"
#include "Device.h"
#include "Rectangle.h"

class Level {
private:
	std::vector<Block*> blocks{};
	int borderLeft;
	int borderTop;
	int borderRight;
	Device* device;
	int number;
public:
	Level(Device* d);
	Level(Device* d, int number);
	~Level();

	int getBorderLeft();
	int getBorderTop();
	int getBorderRight();

	void addBlock(Block* block);
	std::vector<Block*> getBlocks();
	int getNumber();

	Rectangle* getBorderLeftRect();
	Rectangle* getBorderTopRect();
	Rectangle* getBorderRightRect();
};

#endif
