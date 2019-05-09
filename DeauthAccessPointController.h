#ifndef _DEAUTHACCESSPOINTCONTROLLER_H
#define _DEAUTHACCESSPOINTCONTROLLER_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "ESP8266WiFi.h"
#include "BaseController.h"
#include "Menu.h"
#include "ListAccessPointsController.h"
#include "SimpleList.h"

class DeauthAccessPointController : public BaseController
{
    private:
        Menu menu;
        U8G2 dsp;
        int wifiIndex;
        bool isRunning;

    public:
        DeauthAccessPointController(U8G2 _dsp, int _wifiIndex);
        void render();
        void buttonSelect(SimpleList<BaseController *> *controllers);
        void buttonDown();
        void buttonUp();
};


#endif // _DEAUTHACCESSPOINTCONTROLLER_H
