#ifndef _BALL_
#define _BALL_

class Ball {
  private:
    bool moving;
    float positionX;
    float positionY;
    int radius;
    float speedX;
    float speedY;
  public:
    Ball(const float x, const float y, const int r);

    float getPositionX() const;
	void setPositionX(float x);

    float getPositionY() const;
	void setPositionY(float y);

    int getRadius() const;
	void setRadius(int r);

    float getSpeedX() const;
	void setSpeedX(float s);

    float getSpeedY() const;
	void setSpeedY(float s);

	bool isMoving() const;
	void setMoving(bool m);

	void invertMovementX();
	void invertMovementY();
};

#endif
