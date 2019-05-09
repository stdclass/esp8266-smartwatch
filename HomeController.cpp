
#include "HomeController.h"

HomeController::HomeController(U8G2 _dsp)
{
    dsp = _dsp;

    menu.setDisplay(dsp);

    menu.addItem("Clock");
    menu.addItem("Access Points");

    // Preloading Controller, so navigation is nearly instant
    menuControllers.add(new ClockController(dsp));
    menuControllers.add(new ListAccessPointsController(dsp));
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
