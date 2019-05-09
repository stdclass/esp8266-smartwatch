
#include "ClockController.h"

ClockController::ClockController(U8G2 _dsp)
{
    dsp = _dsp;

    hours = random(25);
    minutes = random(61);
}


void ClockController::render()
{
    String time = String(hours) + String(":") + String(minutes);

    dsp.clearBuffer();
    dsp.setFont(u8g2_font_helvB18_te);

    int timeHeight = 18;
    int timeWidth = dsp.getStrWidth(time.c_str());

    int posX = (dsp.getDisplayWidth() / 2) - (timeWidth / 2);
    int posY = (dsp.getDisplayHeight() / 2) + (timeHeight / 2);

    dsp.setCursor(posX, posY);
    dsp.print(time);
    dsp.sendBuffer();
}


void ClockController::buttonSelect(SimpleList<BaseController *> *controllers)
{
    controllers->pop();
}


void ClockController::buttonDown()
{
    hours--;
}


void ClockController::buttonUp()
{
    hours++;
}
