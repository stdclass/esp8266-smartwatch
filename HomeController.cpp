
#include "HomeController.h"

HomeController::HomeController(U8G2 dsp)
{
  menu.setDisplay(dsp);
  
  menu.addItem("Clock");
  menu.addItem("Access Points");
  menu.addItem("Settings");
  menu.addItem("Settings 2");
  menu.addItem("Settings 3");
  menu.addItem("Settings 4");
  menu.addItem("Settings 5");

  menuControllers.push(new AccessPointsController(dsp));
  menuControllers.push(new AccessPointsController(dsp));
  menuControllers.push(new AccessPointsController(dsp));
}


void HomeController::render()
{
  menu.render();
  
}


void HomeController::buttonSelect(StackArray<BaseController *> *controllers)
{
  controllers->push(
    menuControllers.at(menu.getActiveIndex())
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
