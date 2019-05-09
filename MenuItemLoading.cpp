
#include "MenuItemLoading.h"

#define BOX_WIDTH 30
#define BOX_SPEED 3

MenuItemLoading::MenuItemLoading(bool _loading)
{
    loading = _loading;
    selected = false;
    posX = 0;

    // 1 = right, 0 left
    dir = 1;
}

void MenuItemLoading::setSelected(bool _selected)
{
    selected = _selected;
}

void MenuItemLoading::render(U8G2 dsp, int posY)
{
    if( loading ){
        posX = (dir == 1) ? posX + BOX_SPEED : posX - BOX_SPEED;

        if( posX + BOX_WIDTH >= dsp.getDisplayWidth() ){
            dir = 0;
        }
        if( posX <= 0 ){
            dir = 1;
        }

        dsp.drawBox(posX, posY - 5, BOX_WIDTH, 5);
    }
}

bool MenuItemLoading::isFixed()
{
    return false;
}
