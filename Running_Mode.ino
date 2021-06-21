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


tft.fillRoundRect(5,3,65,25,10, TFT_BLUE);
tft.fillRoundRect(100,3,65,25,10, TFT_BLUE);
tft.fillRoundRect(200,3,65,25,10, TFT_BLUE);
tft.setTextSize(2);
tft.setTextColor(TFT_BLACK);
tft.drawString("Graph",205,35);
tft.drawString("Menu", 10, 35);
tft.drawString("Back", 103, 35);







  

}

void loop() {
















  

}
