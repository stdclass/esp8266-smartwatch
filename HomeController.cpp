
#include "HomeController.h"

HomeController::HomeController(U8G2 _dsp)
{
  dsp = _dsp;
  
  menu.setDisplay(dsp);
  
  menu.addItem("Access Points");

  menuControllers.add(new AccessPointsController(dsp));
}


void HomeController::render()
{
  menu.render();
  
}


void HomeController::buttonSelect(SimpleList<BaseController *> *controllers)
{
  controllers->add(
    menuControllers.get(menu.getActiveIndex())
  );
}


void HomeController::buttonDown()
{
  menu.selectNextItem();
}


void HomeController::buttonUp()
{
  menu.selectPreviousItem();
}
