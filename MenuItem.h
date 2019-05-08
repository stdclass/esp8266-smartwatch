#ifndef _MENUITEM_H
#define _MENUITEM_H

#include <Arduino.h>

class MenuItem
{
  String title;
  bool selectable;
  
  public:
    MenuItem(String _title, bool _selectable = true);
    String getTitle();
    bool isSelectable();
};

#endif // _MENUITEM_H
