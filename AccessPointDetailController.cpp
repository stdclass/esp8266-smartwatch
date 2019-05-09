
#include "AccessPointDetailController.h"

AccessPointDetailController::AccessPointDetailController(U8G2 _dsp, int _wifiIndex)
{
    dsp = _dsp;
    wifiIndex = _wifiIndex;

    menu.setDisplay(dsp);

    String encryptionName = "unkown";

    byte encryption = WiFi.encryptionType(wifiIndex);

    switch (encryption) {
        case ENC_TYPE_NONE:
            encryptionName = "none";
            break;

        case ENC_TYPE_WEP:
            encryptionName = "WEP";
            break;

        case ENC_TYPE_TKIP:
            encryptionName = "WPA";
            break;

        case ENC_TYPE_CCMP:
            encryptionName = "WPA2";
            break;

        case ENC_TYPE_AUTO:
            encryptionName = "auto";
            break;
    }

    menu.addBack();
    menu.setTitle(WiFi.SSID(wifiIndex));
    menu.addItem("RSSI: " + String(WiFi.RSSI(wifiIndex)), false);
    menu.addItem("Channel: " + String(WiFi.channel(wifiIndex)), false);
    menu.addItem("Security: " + encryptionName, false);
    menu.addItem("Deauth");
}


void AccessPointDetailController::render()
{
    menu.render();
}


void AccessPointDetailController::buttonSelect(SimpleList<BaseController *> *controllers)
{
    if( menu.getActiveIndex() == 0 ){
        controllers->pop();
    }

    if( menu.getActiveIndex() == 4 ){
        controllers->add(
            new DeauthAccessPointController(dsp, wifiIndex)
        );
    }
}

void AccessPointDetailController::buttonDown()
{
    menu.selectNextItem();
}

void AccessPointDetailController::buttonUp()
{
    menu.selectPreviousItem();
}
