#ifndef _MENUITEM_H
#define _MENUITEM_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "BaseMenuItem.h"

class MenuItem : public BaseMenuItem
{
    String title;
    bool selectable;
    bool selected;

    public:
        MenuItem(String _title, bool _selectable = true);
        void setSelected(bool _selected);
        void render(U8G2 dsp, int posY);
        bool isFixed();
};

#endif // _MENUITEM_H
