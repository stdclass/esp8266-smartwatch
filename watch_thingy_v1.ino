

#include "ESP8266WiFi.h"
#include <Arduino.h>
#include <U8g2lib.h>
#include "SimpleList.h"
#include "BaseController.h"
#include "HomeController.h"

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

#define BUTTON_X A0
#define BUTTON_SW D3

int buttonX = 0;
int buttonSWDown = 0;
unsigned long buttonSWLastPressed = 0;



SimpleList<BaseController *> controllerStack;

void setup(void) {
    u8g2.begin();
    u8g2.enableUTF8Print();

    Serial.begin(115200);

    pinMode(BUTTON_X, INPUT);
    pinMode(BUTTON_SW, INPUT);

    HomeController *homeController = new HomeController(u8g2);

    controllerStack.add(homeController);
}


void loop(void) {

    BaseController *controller = controllerStack.getLast();
    controller->render();


    if( digitalRead(BUTTON_SW) == LOW && buttonSWDown == 0){
        controller->buttonSelect(&controllerStack);

        buttonSWDown = 1;
    }

    if( digitalRead(BUTTON_SW) == HIGH ){
        buttonSWDown = 0;
    }

    int buttonXRaw = analogRead(BUTTON_X);

    if ( buttonXRaw < 10 && buttonX != -1 ) {
        buttonX = -1;
        controller->buttonDown();

    } else if ( buttonXRaw > 1014 && buttonX != 1 ) {
        buttonX = 1;
        controller->buttonUp();

    } else if ( buttonX != 0 && buttonXRaw >= 10 && buttonXRaw <= 1014 ) {
        buttonX = 0;
    }

}
