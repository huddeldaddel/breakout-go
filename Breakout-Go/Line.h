#ifndef _LINE_
#define _LINE_

#include "Point.h"

class Line {
private:
	float x1;
	float y1;
	float x2;
	float y2;
public:
	Line(float x1, float y1, float x2, float y2);
	~Line();

	float getX1() const;
	float getX2() const;
	float getY1() const;
	float getY2() const;
};

#endif
