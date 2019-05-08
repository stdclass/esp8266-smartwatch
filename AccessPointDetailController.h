#ifndef _ACCESSPOINTDETAILCONTROLLER_H
#define _ACCESSPOINTDETAILCONTROLLER_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "ESP8266WiFi.h"
#include "BaseController.h"
#include "Menu.h"
#include "ListAccessPointsController.h"
#include "SimpleList.h"

class AccessPointDetailController : public BaseController
{
  private:
    Menu menu;
    U8G2 dsp;
    int wifiIndex;

  public:
    AccessPointDetailController(U8G2 _dsp, int _wifiIndex);
    void render();
    void buttonSelect(SimpleList<BaseController *> *controllers);
    void buttonDown();
    void buttonUp();
};


#endif // _ACCESSPOINTDETAILCONTROLLER_H
