#ifndef _RECTANGLE_
#define _RECTANGLE_

#include "Line.h"

class Rectangle {
private:
  int positionX;
  int positionY;
  int width;
  int height;
public :
	Rectangle(int x, int y, int w, int h);
	~Rectangle();

	int getPositionX() const;
	int getPositionY() const;
	int getWidth() const;
	int getHeight() const;

	virtual int hit();

	Line* getLeftBorder() const;
	Line* getTopBorder() const;
	Line* getBottomBorder() const;
	Line* getRightBorder() const;

	bool operator==(const Rectangle& other) const;
	bool operator!=(const Rectangle& other) const;
};

#endif
