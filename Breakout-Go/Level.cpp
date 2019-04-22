#include "Level.h"

Level::Level(Device* d) : device{ d }, borderLeft{ 10 }, borderTop{ 20 }, borderRight{ 10 } {
	for (int i = 0; i < 15; i++) {
		addBlock(new Block(10 + i * 20, 60, 20, 10, 0xCA49, 1, 10));
		addBlock(new Block(10 + i * 20, 70, 20, 10, 0xC347, 1, 10));
		addBlock(new Block(10 + i * 20, 80, 20, 10, 0xB3C6, 1, 10));
		addBlock(new Block(10 + i * 20, 90, 20, 10, 0xA525, 1, 10));
		addBlock(new Block(10 + i * 20, 100, 20, 10, 0x4D09, 1, 10));
		addBlock(new Block(10 + i * 20, 110, 20, 10, 0x4239, 1, 10));
	}
}

Level::~Level() {
	for (int i = 0; i < blocks.size(); i++)
		delete blocks.at(i);
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