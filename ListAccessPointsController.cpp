
#include "ListAccessPointsController.h"

ListAccessPointsController::ListAccessPointsController(U8G2 _dsp)
{
    dsp = _dsp;

    WiFi.mode(WIFI_STA);
    WiFi.disconnect();

    int n = WiFi.scanNetworks();

    menu.setDisplay(dsp);

    menu.addBack();

    if (n == 0) {
    } else {
        for (int i = 0; i < n; ++i) {
            String ssidString = fixUtf8( WiFi.SSID(i) );

            menu.addItem( ssidString );
        }
    }

}


void ListAccessPointsController::render()
{
    menu.render();
}


void ListAccessPointsController::buttonSelect(SimpleList<BaseController *> *controllers)
{
    if( menu.getActiveIndex() == 0 ){
        controllers->pop();
    }else{
        controllers->add(
            new AccessPointDetailController(dsp, menu.getActiveIndex() - 1)
        );
    }
}

void ListAccessPointsController::buttonDown()
{
    menu.selectNextItem();
}

void ListAccessPointsController::buttonUp()
{
    menu.selectPreviousItem();
}
