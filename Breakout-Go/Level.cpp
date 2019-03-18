#include "Level.h"

// Currently just some default values for an empty first level
Level::Level(Device* d) : device{d}, number{1}, borderLeft{5}, borderTop{5}, borderRight{5} {
}

Level::Level(Device* d, int number) : device{ d }, number{ number }, borderLeft{ 10 }, borderTop{ 20 }, borderRight{ 10 } {
}

Level::~Level() {
	for (int i = 0; i < blocks.size(); i++)
		delete blocks.at(i);
}

int Level::getNumber() {
	return number;
}

int Level::getBorderLeft() {
	return borderLeft;
}

int Level::getBorderTop() {
	return borderTop;
}

int Level::getBorderRight() {
	return borderRight;
}

Rectangle* Level::getBorderLeftRect() {
	return new Rectangle(0, 0, borderLeft, device->getScreenHeight());
}

Rectangle* Level::getBorderTopRect() {
	return new Rectangle(0, 0, device->getScreenWidth(), borderTop);
}

Rectangle* Level::getBorderRightRect() {
	return new Rectangle(device->getScreenWidth() - borderRight, 0, borderRight, device->getScreenHeight());   
}

std::vector<Block*> Level::getBlocks() {
	return blocks;
}

void Level::addBlock(Block* block) {
	blocks.push_back(block);
}