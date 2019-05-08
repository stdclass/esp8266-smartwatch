
#include "Menu.h"

#define MENU_ITEM_SIZE 15

Menu::Menu()
{
  activeIndex = 0;
  lastActiveIndex = -1;
  translateY = 0;

  items = new SimpleList<MenuItem *>;
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

void Menu::setDisplay(U8G2 dsp)
{
  u8g2 = dsp;
}

void Menu::render()
{

  if( lastActiveIndex == activeIndex ){
    //return;
  }

  lastActiveIndex = activeIndex;
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_mercutio_basic_nbp_t_all);

  for( int i = 0; i < items->size(); i++ ){
    
    int posY = getOffsetTop(i);

    if( posY < 0 || posY > ( u8g2.getDisplayHeight() ) ){
      continue;
    }
    
    MenuItem *item = items->get(i);

    bool isSelected = ( activeIndex == i && item->isSelectable() );
    
    u8g2.setCursor(10, posY);
    u8g2.print(item->getTitle());

    if( isSelected ){
      u8g2.setFont(u8g2_font_open_iconic_all_1x_t);
      u8g2.drawStr(0, posY - 2, "o");
      u8g2.setFont(u8g2_font_mercutio_basic_nbp_t_all);
    }
  }

  u8g2.sendBuffer();
}

void Menu::selectNextItem()
{
  if( activeIndex + 1 >= items->size() ){
    return;
  }
  
  activeIndex++;

  /*MenuItem *item = items->get(activeIndex);
  
  if( ! item->isSelectable() ){
    selectNextItem();
  }*/

  if( getOffsetTop(activeIndex) > u8g2.getDisplayHeight() ){
    translateY -= MENU_ITEM_SIZE;
  }
}


void Menu::selectPreviousItem()
{
  activeIndex--;

  if( activeIndex < 0 ){
    activeIndex = 0;
  }/*else{
    MenuItem *item = items->get(activeIndex);
    if( ! item->isSelectable() ){
      selectPreviousItem();
    }
  }*/

  if( getOffsetTop(activeIndex) < MENU_ITEM_SIZE ){
    translateY += MENU_ITEM_SIZE;
  }
}


int Menu::getActiveIndex()
{
  return activeIndex;
}
