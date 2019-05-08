#ifndef _LISTACCESSPOINTSCONTROLLER_H
#define _LISTACCESSPOINTSCONTROLLER_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "ESP8266WiFi.h"
#include "BaseController.h"
#include "Menu.h"

class ListAccessPointsController : public BaseController
{
  private:
    Menu menu;

  public:
    ListAccessPointsController(U8G2 dsp);
    void render();
    void buttonSelect(StackArray<BaseController *> *controllers);
    void buttonDown();
    void buttonUp();
};


#endif // _LISTACCESSPOINTSCONTROLLER_H
