
#include "AccessPointsController.h"

AccessPointsController::AccessPointsController(U8G2 _dsp)
{
  dsp = _dsp;
  
  menu.setDisplay(dsp);
  
  menu.addItem("Back");
  menu.addItem("List Access Points");
}


void AccessPointsController::render()
{
  menu.render();
}


void AccessPointsController::buttonSelect(SimpleList<BaseController *> *controllers)
{
  if( menu.getActiveIndex() == 0 ){
    controllers->pop();
  }
  if( menu.getActiveIndex() == 1 ){
    controllers->add(
      new ListAccessPointsController(dsp)
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
