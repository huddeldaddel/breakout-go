#ifndef _LEVEL_
#define _LEVEL_

#include "Rectangle.h"

class Level {
  private:
    int number;
    int borderLeft;
    int borderTop;
    int borderRight;
  public:
    Level();
    
    int getNumber();
    int getBorderLeft();
    int getBorderTop();
    int getBorderRight();

    Rectangle getBorderLeftRect();
    Rectangle getBorderTopRect();
    Rectangle getBorderRightRect();
};

#endif
