
#include "Menu.h"

#define MENU_ITEM_SIZE 15

Menu::Menu()
{
    translateY = 0;
    activeIndex = 0;
    hasBack = false;
    title = "";

    items = new SimpleList<BaseMenuItem *>;
}

int Menu::getOffsetTop(int itemIndex)
{
    return (MENU_ITEM_SIZE * itemIndex) + MENU_ITEM_SIZE + translateY;
}

void Menu::addItem(String title, bool selectable)
{
    MenuItem *item = new MenuItem(title, selectable);

    items->add(item);
}

void Menu::addBack()
{
    MenuItemBack *item = new MenuItemBack();

    items->add(item);

    hasBack = true;
}

void Menu::setTitle(String _title)
{
    title = _title;
}

void Menu::updateItem(int index, String title, bool selectable)
{
    MenuItem *item = new MenuItem(title, selectable);

    items->replace(index, item);
}

void Menu::addLoading(bool loading)
{
    MenuItemLoading *item = new MenuItemLoading(loading);

    items->add(item);
}

void Menu::startLoading(int index)
{
    MenuItemLoading *item = new MenuItemLoading(true);

    items->replace(index, item);
}

void Menu::stopLoading(int index)
{
    MenuItemLoading *item = new MenuItemLoading(false);

    items->replace(index, item);
}

void Menu::setDisplay(U8G2 _dsp)
{
    dsp = _dsp;
}

void Menu::render()
{
    dsp.clearBuffer();
    dsp.setFont(u8g2_font_mercutio_basic_nbp_t_all);

    if( title != "" ){
        int titleWidth = dsp.getStrWidth(title.c_str());
        dsp.setCursor(dsp.getDisplayWidth() - titleWidth, MENU_ITEM_SIZE - 5);
        dsp.print(title.substring(0,15));
    }

    int minTopPosition = hasBack ? MENU_ITEM_SIZE + 5 : 0;

    for( int i = 0; i < items->size(); i++ ){

        int posY = (MENU_ITEM_SIZE * i) + MENU_ITEM_SIZE + translateY;

        BaseMenuItem *item = items->get(i);

        if( ( posY < minTopPosition || posY > ( dsp.getDisplayHeight() ) ) && ! item->isFixed() ){
            continue;
        }


        item->setSelected(activeIndex == i);
        item->render(dsp, posY);

    }

    dsp.sendBuffer();
}

void Menu::selectNextItem()
{
    if( activeIndex + 1 >= items->size() ){
        return;
    }

    activeIndex++;

    if( getOffsetTop(activeIndex) > dsp.getDisplayHeight() ){
        translateY -= MENU_ITEM_SIZE;
    }
}


void Menu::selectPreviousItem()
{
    activeIndex--;

    if( activeIndex < 0 ){
        activeIndex = 0;
    }

    int threshold = hasBack ? MENU_ITEM_SIZE + 5 : MENU_ITEM_SIZE;

    if( activeIndex > 0 && getOffsetTop(activeIndex) < threshold ){
        translateY += MENU_ITEM_SIZE;
    }
}


int Menu::getActiveIndex()
{
    return activeIndex;
}
