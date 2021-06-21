
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


  
  tft.fillRoundRect(1,1,315,235,5, TFT_GREEN);
  tft.setTextColor(TFT_WHITE);
  tft.setTextSize(3);
  
  tft.drawString(" Training Mode", 30,5 );
  tft.drawString("________________________",3,15);
  tft.setTextSize(2);
  tft.drawString("Number of Training", 50,110);
  tft.drawRoundRect(80,130,165,80,20, TFT_WHITE);
  tft.setTextSize(5);
  tft.drawString("/10",147,150);

tft.setTextSize(2);
  tft.setTextColor(TFT_WHITE);
tft.fillRoundRect(5,220,65,25,10, TFT_BLUE);
tft.drawString("Delete last Training", 100, 215);

 

}

void loop() {
  // put your main code here, to run repeatedly:

}
