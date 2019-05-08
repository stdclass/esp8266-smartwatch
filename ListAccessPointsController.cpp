
#include "ListAccessPointsController.h"

ListAccessPointsController::ListAccessPointsController(U8G2 dsp)
{

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  
  int n = WiFi.scanNetworks();

  
  menu.setDisplay(dsp);
  
  menu.addItem("Back");
  
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
      Serial.println(WiFi.SSID(i));

      /**
       * TODO: set menu.addItem param to string. move menu render function to u8g2.print() instead of drawStr
       */
      menu.addItem( const_cast<char*>(WiFi.SSID(i).c_str()) );
    }
  }

}


void ListAccessPointsController::render()
{
  menu.render();
}


void ListAccessPointsController::buttonSelect(StackArray<BaseController *> *controllers)
{
  if( menu.getActiveIndex() == 0 ){
    controllers->pop();
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
