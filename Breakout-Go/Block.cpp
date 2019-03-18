#include "Block.h"

Block::Block(int x, int y, int w, int h, unsigned int color, int durability, int points) : 
	Rectangle(x, y, w, h), color{ color }, durability{ durability }, points{ points } {
}

Block::~Block() {
}

unsigned int Block::getColor() const {
	return color;
}

int Block::getDurability() const {
	return durability;
}

int Block::getPoints() const {
	return points;
}

int Block::hit() {
	durability--;
	return (durability == 0) ? getPoints() : 0;
}