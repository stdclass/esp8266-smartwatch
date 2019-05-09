#ifndef _MENUITEMLOADING_H
#define _MENUITEMLOADING_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "BaseMenuItem.h"

class MenuItemLoading : public BaseMenuItem
{
    bool selected;
    bool loading;
    int posX;
    int dir;

    public:
        MenuItemLoading(bool _loading = false);
        void setSelected(bool _selected);
        void render(U8G2 dsp, int posY);
        bool isFixed();
};

#endif // _MENUITEMLOADING_H
