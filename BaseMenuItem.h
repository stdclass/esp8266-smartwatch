#ifndef _BASEMENUITEM_H
#define _BASEMENUITEM_H

#include <U8g2lib.h>

class BaseMenuItem
{
    public:
        virtual void render(U8G2 dsp, int posY) = 0;
        virtual void setSelected(bool _selected) = 0;
        virtual bool isFixed() = 0;
        virtual ~BaseMenuItem() {}
};

#endif // _BASEMENUITEM_H
