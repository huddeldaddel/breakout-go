#ifndef _RECTANGLE_
#define _RECTANGLE_

struct Rectangle {
  int positionX;
  int positionY;
  int width;
  int height;
#ifdef WIN32
  int mork;
#endif
};

#endif
