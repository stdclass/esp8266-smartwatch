
#include "Menu.h"

#define MENU_ITEM_SIZE 15

Menu::Menu()
{
  activeItem = 0;
  translateY = 0;
}

void Menu::addItem(char *title)
{
  items.push(title);
}

void Menu::setDisplay(U8G2 dsp)
{
  u8g2 = dsp;
}

void Menu::render()
{
  
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_mercutio_basic_nbp_t_all);

  for( int i = 0; i < items.count(); i++ ){
    
    int posY = (MENU_ITEM_SIZE * i) + MENU_ITEM_SIZE + translateY;
    int posX = activeItem == i ? 10 : 0;

    if( posY < 0 || posY > ( u8g2.getDisplayHeight() + MENU_ITEM_SIZE ) ){
      continue;
    }
    
    u8g2.drawStr(posX, posY, items.at(i));

    if( activeItem == i ){
      u8g2.setFont(u8g2_font_open_iconic_all_1x_t);
      u8g2.drawStr(0, posY - 2, "o");
      u8g2.setFont(u8g2_font_mercutio_basic_nbp_t_all);
    }
  }

  u8g2.sendBuffer();
}

void Menu::selectNextItem()
{
  activeItem++;

  if( activeItem >= items.count() ){
    activeItem = items.count() - 1;
  }

  int top = ( activeItem * MENU_ITEM_SIZE ) + MENU_ITEM_SIZE + translateY;

  if( top > u8g2.getDisplayHeight() ){
    translateY -= MENU_ITEM_SIZE;
  }
}


void Menu::selectPreviousItem()
{
  activeItem--;

  if( activeItem < 0 ){
    activeItem = 0;
  }
  
  int top = ( activeItem * MENU_ITEM_SIZE ) + MENU_ITEM_SIZE + translateY;

  if( top < MENU_ITEM_SIZE ){
    translateY += MENU_ITEM_SIZE;
  }
}


int Menu::getActiveIndex()
{
  return activeItem;
}
