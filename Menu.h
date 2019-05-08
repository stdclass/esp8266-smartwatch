#ifndef _MENU_H
#define _MENU_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "SimpleList.h"
#include "MenuItem.h"

class Menu
{
  private:
    SimpleList<MenuItem *> *items;
    int activeIndex;
    int lastActiveIndex;
    int translateY;
    U8G2 u8g2;
    int getOffsetTop(int itemIndex);
    
  public:
    Menu();
    void render();
    void addItem(String title, bool selectable = true);
    void setDisplay(U8G2 dsp);
    void selectNextItem();
    void selectPreviousItem();
    int getActiveIndex();
};

#endif 
