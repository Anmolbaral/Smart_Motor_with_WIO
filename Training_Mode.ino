#include "TFT_eSPI.h"
TFT_eSPI tft;




void setup() {
tft.begin();
tft.setRotation(3);
tft.fillScreen(TFT_WHITE);
tft.setTextColor(TFT_BLACK);
tft.setTextSize(2);

   pinMode(WIO_KEY_A, INPUT);
   pinMode(WIO_5S_RIGHT, INPUT);
   pinMode(WIO_5S_LEFT, INPUT);
   pinMode(WIO_BUZZER, OUTPUT);
   pinMode(WIO_LIGHT, INPUT);
   pinMode(WIO_5S_DOWN, INPUT);
   pinMode(WIO_5S_PRESS, INPUT);

tft.fillRoundRect(2,50,315,185,5, TFT_RED);
    tft.setTextSize(3);
    tft.setTextColor(TFT_WHITE);
    tft.drawString("Running Mode",30,55);
    tft.drawString("________________________",3,60);








  

}

void loop() {
















  

}
