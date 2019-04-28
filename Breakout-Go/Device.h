#ifndef _DEVICE_
#define _DEVICE_

class Device {
  public:
	virtual void drawScreenRect(const int x, const int y, const int w, const int h, const unsigned int color) = 0;
    virtual void fillScreenRect(const int x, const int y, const int w, const int h, const unsigned int color) = 0;
	virtual void fillScreenCircle(const int x, const int y, const int r, const unsigned int color) = 0;
    
    virtual int getScreenWidth() const = 0;
    virtual int getScreenHeight() const = 0;
  
    virtual bool isButtonAPressed() const = 0;
    virtual bool isButtonBPressed() const = 0;  
    virtual bool isDirectionDownPressed() const = 0;
    virtual bool isDirectionLeftPressed() const = 0;
    virtual bool isDirectionUpPressed() const = 0;
    virtual bool isDirectionRightPressed() const = 0;

	virtual void play(const unsigned char* music_data) const = 0;
	virtual void print(const int lives, const long score) const = 0;

    virtual void sleep(const int millis) const = 0;
};

#endif
