#ifndef _ACCESSPOINTSCONTROLLER_H
#define _ACCESSPOINTSCONTROLLER_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "BaseController.h"
#include "Menu.h"
#include "ListAccessPointsController.h"
#include "SimpleList.h"

class AccessPointsController : public BaseController
{
  private:
    Menu menu;
    U8G2 dsp;

  public:
    AccessPointsController(U8G2 _dsp);
    void render();
    void buttonSelect(SimpleList<BaseController *> *controllers);
    void buttonDown();
    void buttonUp();
};


#endif // _ACCESSPOINTSCONTROLLER_H
