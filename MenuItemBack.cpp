
#include "MenuItemBack.h"


MenuItemBack::MenuItemBack()
{
    selected = false;
}

void MenuItemBack::setSelected(bool _selected)
{
    selected = _selected;
}

void MenuItemBack::render(U8G2 dsp, int posY)
{
    posY = 15;

    dsp.setCursor(10, posY - 5);
    dsp.print("Back");

    if( selected ){
        dsp.setFont(u8g2_font_open_iconic_all_1x_t);
        dsp.drawStr(0, posY - 6, "n");
        dsp.setFont(u8g2_font_mercutio_basic_nbp_t_all);
    }

    dsp.drawHLine(10, posY - 1, dsp.getDisplayWidth() - 10);
}

bool MenuItemBack::isFixed()
{
    return true;
}
