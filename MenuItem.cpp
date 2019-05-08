
#include "MenuItem.h"


MenuItem::MenuItem(String _title, bool _selectable )
{
  title = _title;
  selectable = _selectable;
}

String MenuItem::getTitle()
{
  return title;
}

bool MenuItem::isSelectable()
{
  return selectable;
}
