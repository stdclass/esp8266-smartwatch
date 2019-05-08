#ifndef _ACCESSPOINTSCONTROLLER_H
#define _ACCESSPOINTSCONTROLLER_H

#include <Arduino.h>
#include <U8g2lib.h>
#include"BaseController.h"
#include "Menu.h"
#include "ListAccessPointsController.h"

class AccessPointsController : public BaseController
{
  private:
    Menu menu;
    U8G2 u8g2;

  public:
    AccessPointsController(U8G2 dsp);
    void render();
    void buttonSelect(StackArray<BaseController *> *controllers);
    void buttonDown();
    void buttonUp();
};


#endif // _ACCESSPOINTSCONTROLLER_H
