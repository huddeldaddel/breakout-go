#include "Level.h"

Level::Level(Device* d) : device{ d }, borderLeft{ 10 }, borderTop{ 20 }, borderRight{ 10 } {
	initBlocks();
}

Level::~Level() {
	for (int i = 0; i < blocks.size(); i++)
		delete blocks.at(i);
}

void Level::initBlocks() {
	for (int i = 0; i < 15; i++) {
		addBlock(new Block(10 + i * 20,  60, 20, 10, 0xCA49, 1, 50));
		addBlock(new Block(10 + i * 20,  70, 20, 10, 0xC347, 1, 30));
		addBlock(new Block(10 + i * 20,  80, 20, 10, 0xB3C6, 1, 25));
		addBlock(new Block(10 + i * 20,  90, 20, 10, 0xA525, 1, 20));
		addBlock(new Block(10 + i * 20, 100, 20, 10, 0x4D09, 1, 15));
		addBlock(new Block(10 + i * 20, 110, 20, 10, 0x4239, 1, 10));
	}
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

bool Level::isWon() {
	for (int i = 0; i < getBlocks().size(); i++) 
		if (0 < getBlocks().at(i)->getDurability())
			return false;
	return true;
}

void Level::reset() {
	for (int i = 0; i < blocks.size(); i++)
		delete blocks.at(i);
	blocks.clear();
	initBlocks();
}