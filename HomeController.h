#ifndef _HOMECONTROLLER_H
#define _HOMECONTROLLER_H

#include <Arduino.h>
#include <U8g2lib.h>
#include"BaseController.h"
#include "Menu.h"
#include "StackArray.h"
#include "AccessPointsController.h"

class HomeController : public BaseController
{
  private:
    Menu menu;
    StackArray<BaseController *> menuControllers;

  public:
    HomeController(U8G2 dsp);
    void render();
    void buttonSelect(StackArray<BaseController *> *controllers);
    void buttonDown();
    void buttonUp();
};

#endif
