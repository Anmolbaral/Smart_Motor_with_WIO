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



   tft.drawRoundRect(3,3,310,30,5, TFT_BLUE);
tft.drawString("1. Run App",5,8);

tft.drawRoundRect(3,35,310,30,5, TFT_BLUE);
tft.drawString("2. Read Information", 10, 40);

tft.drawRoundRect(3,70,310,165,20, TFT_BLUE);
tft.drawCircle(50,125,42, TFT_BLUE);
tft.drawCircle(50,125,13, TFT_BLUE);
tft.fillTriangle(35,105,68,105,50,85, TFT_BLUE);
tft.fillTriangle(35,145,68,145,50,165, TFT_BLUE);
tft.fillCircle(50,125,10,TFT_BLUE);


tft.setTextSize(3);
tft.drawString("Select", 115,120);

tft.drawFastHLine(3,185,310, TFT_BLUE);
tft.fillCircle(50,205,10,TFT_BLUE);
tft.drawCircle(50,205,13, TFT_BLUE);
tft.drawString("Enter", 115,200);
  

}

void loop() {
  








}
