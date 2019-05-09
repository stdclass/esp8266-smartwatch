
#include "DeauthAccessPointController.h"

DeauthAccessPointController::DeauthAccessPointController(U8G2 _dsp, int _wifiIndex)
{
    dsp = _dsp;
    wifiIndex = _wifiIndex;
    isRunning = false;

    menu.setDisplay(dsp);

    menu.addBack();
    menu.setTitle(WiFi.SSID(wifiIndex));
    menu.addItem("Start Deauthing");
    menu.addLoading(isRunning);
}


void DeauthAccessPointController::render()
{
    menu.render();
}


void DeauthAccessPointController::buttonSelect(SimpleList<BaseController *> *controllers)
{
    if( menu.getActiveIndex() == 0 ){
        controllers->pop();
    }

    if( menu.getActiveIndex() == 1 ){
        if( isRunning ){
            menu.updateItem(1, "Start Deauthing");
            menu.stopLoading(2);
        }else{
            menu.updateItem(1, "Stop Deauthing");
            menu.startLoading(2);
        }

        isRunning = !isRunning;
    }

}

void DeauthAccessPointController::buttonDown()
{
    menu.selectNextItem();
}

void DeauthAccessPointController::buttonUp()
{
    menu.selectPreviousItem();
}
