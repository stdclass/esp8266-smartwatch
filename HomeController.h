#ifndef _HOMECONTROLLER_H
#define _HOMECONTROLLER_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "BaseController.h"
#include "Menu.h"
#include "SimpleList.h"
#include "AccessPointsController.h"

class HomeController : public BaseController
{
  private:
    Menu menu;
    U8G2 dsp;
    SimpleList<BaseController *> menuControllers;

  public:
    HomeController(U8G2 _dsp);
    void render();
    void buttonSelect(SimpleList<BaseController *> *controllers);
    void buttonDown();
    void buttonUp();
};

#endif
