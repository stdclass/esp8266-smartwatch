#ifndef _MENU_H
#define _MENU_H

#include <Arduino.h>
#include <U8g2lib.h>
#include <U8g2lib.h>
#include "StackArray.h"

class Menu
{
  StackArray<char *> items;
  int activeItem;
  int translateY;
  U8G2 u8g2;
  
  public:
    Menu();
    void render();
    void addItem(char *title);
    void setDisplay(U8G2 dsp);
    void selectNextItem();
    void selectPreviousItem();
    int getActiveIndex();
};

#endif 
