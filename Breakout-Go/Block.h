#ifndef _BLOCK_
#define _BLOCK_

#include "Rectangle.h"

class Block : public Rectangle {
private:
	unsigned int color;
	int durability;
	int points;
public:
	Block(int x, int y, int w, int h, unsigned int color, int durability, int points);
	~Block();

	unsigned int getColor() const;
	int getDurability() const;
	int getPoints() const;

	bool decreaseDurability();
};

#endif
