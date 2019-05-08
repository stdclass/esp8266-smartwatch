
#include "AccessPointsController.h"

AccessPointsController::AccessPointsController(U8G2 dsp)
{
  u8g2 = dsp;
  
  menu.setDisplay(dsp);
  
  menu.addItem("Back");
  menu.addItem("List Access Points");
}


void AccessPointsController::render()
{
  menu.render();
}


void AccessPointsController::buttonSelect(StackArray<BaseController *> *controllers)
{
  if( menu.getActiveIndex() == 0 ){
    controllers->pop();
  }
  if( menu.getActiveIndex() == 1 ){
    controllers->push(
      new ListAccessPointsController(u8g2)
    );
  }
}

void AccessPointsController::buttonDown()
{
  menu.selectNextItem();
}

void AccessPointsController::buttonUp()
{
  menu.selectPreviousItem(); 
}
