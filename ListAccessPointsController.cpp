
#include "ListAccessPointsController.h"

ListAccessPointsController::ListAccessPointsController(U8G2 _dsp)
{
  dsp = _dsp;
  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  
  int n = WiFi.scanNetworks();

  
  menu.setDisplay(dsp);
  
  menu.addItem("Back");

  Serial.println(n);
  
  if (n == 0) {
  } else {
    for (int i = 0; i < n; ++i) {
      /*Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i));
      Serial.print(")");
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE) ? " " : "*");
      delay(10);*/

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
