#ifndef _POINT_
#define _POINT_

class Point {
private:
	float x;
	float y;
public:
	Point(float x, float y);
	~Point();

	float getX() const;
	float getY() const;
};

#endif
