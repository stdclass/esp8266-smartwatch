#ifndef _CLOCKCONTROLLER_H
#define _CLOCKCONTROLLER_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "BaseController.h"
#include "SimpleList.h"

class ClockController : public BaseController
{
    private:
        U8G2 dsp;
        int hours;
        int minutes;

    public:
        ClockController(U8G2 _dsp);
        void render();
        void buttonSelect(SimpleList<BaseController *> *controllers);
        void buttonDown();
        void buttonUp();
};

#endif
