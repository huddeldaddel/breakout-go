#ifndef _POINT_
#define _POINT_

#ifdef _DEBUG
	#include <corecrt_math.h>
#else
	// On the Odroid we need that import for various mathematical routines
	#include <odroid_go.h>
#endif

class Point {
private:
	float x;
	float y;
public:
	Point(float x, float y);
	~Point();

	float getX() const;
	float getY() const;

	bool operator==(const Point& other) const;
	bool operator!=(const Point& other) const;
};

#endif
