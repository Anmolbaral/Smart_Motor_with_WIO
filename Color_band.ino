#include "TFT_eSPI.h"

TFT_eSPI tft;
int x=255;
int y=0;
int z=0;
int m=0;
int n=255;
int o= 0;
int a=3;
int b = 3;
int c=3;




void setup() {
  tft.begin();
  tft.setRotation(3);
  tft.fillScreen(TFT_WHITE);
  tft.setTextSize(2);
  
   for(int i=0;i<100; i++){
   tft.setTextColor(tft.color565(x,y,z));
   tft.drawString(".",a,10 );
   
   y+= 4;
   z+=4;
   a+=5;
   }

   
 for(int j=0; j<100; j++){
  tft.setTextColor(tft.color565(m,n,o));
  tft.drawString(".",b,30);

  m+=4;
  o+=4;
  b+=5;
 }

x=0;
y=0;
z=255;
   for(int k=0;k<100; k++){
   tft.setTextColor(tft.color565(x,y,z));
   tft.drawString(".",c,70 );
   
   y+= 4;
   x+=4;
   c+=5;
   }
   
}

  
  


void loop() {


  

}
