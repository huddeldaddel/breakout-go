#ifndef _LINE_
#define _LINE_

#ifdef _DEBUG
	#include <corecrt_math.h>
#else
	// On the Odroid we need that import for various mathematical routines
	#include <odroid_go.h>
#endif

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

	bool operator==(const Line& other) const;
	bool operator!=(const Line& other) const;
};

#endif
