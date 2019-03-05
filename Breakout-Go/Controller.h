#ifndef _CONTROLLER_
#define _CONTROLLER_

class Controller {
  private:
  public:
    Controller();
    ~Controller();
    void resetSlider(Slider* slider, Level* level, Device* device) const;
}

#endif
