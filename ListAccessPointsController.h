#ifndef _LISTACCESSPOINTSCONTROLLER_H
#define _LISTACCESSPOINTSCONTROLLER_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "ESP8266WiFi.h"
#include "BaseController.h"
#include "Menu.h"
#include "Helpers.h"
#include "SimpleList.h"
#include "AccessPointDetailController.h"

class ListAccessPointsController : public BaseController
{
    private:
        Menu menu;
        U8G2 dsp;

    public:
        ListAccessPointsController(U8G2 _dsp);
        void render();
        void buttonSelect(SimpleList<BaseController *> *controllers);
        void buttonDown();
        void buttonUp();
};


#endif // _LISTACCESSPOINTSCONTROLLER_H
