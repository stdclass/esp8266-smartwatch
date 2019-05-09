#ifndef _MENUITEMBACK_H
#define _MENUITEMBACK_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "BaseMenuItem.h"

class MenuItemBack : public BaseMenuItem
{
    bool selected;

    public:
        MenuItemBack();
        void setSelected(bool _selected);
        void render(U8G2 dsp, int posY);
        bool isFixed();
};

#endif // _MENUITEMBACK_H
