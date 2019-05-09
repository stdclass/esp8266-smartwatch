#ifndef _MENU_H
#define _MENU_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "SimpleList.h"
#include "BaseMenuItem.h"
#include "MenuItem.h"
#include "MenuItemLoading.h"
#include "MenuItemBack.h"

class Menu
{
    private:
        SimpleList<BaseMenuItem *> *items;
        int activeIndex;
        int translateY;
        U8G2 dsp;
        int getOffsetTop(int itemIndex);
        bool hasBack;
        String title;

    public:
        Menu();
        void render();
        void addItem(String title, bool selectable = true);
        void addBack();
        void updateItem(int index, String title, bool selectable = true);
        void addLoading(bool loading = false);
        void setTitle(String _title);
        void startLoading(int index);
        void stopLoading(int index);
        void setDisplay(U8G2 _dsp);
        void selectNextItem();
        void selectPreviousItem();
        int getActiveIndex();
};

#endif
