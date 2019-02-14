#ifndef _LEVEL_
#define _LEVEL_

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
};

#endif
