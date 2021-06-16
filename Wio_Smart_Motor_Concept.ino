#include "Servo.h"
#include "TFT_eSPI.h"

Servo myservo;
TFT_eSPI tft;
TFT_eSprite spr= TFT_eSprite (&tft);

int count= 0;
float pos=0;
int i=0;
int training[10][2];
int brightness= 0;
int mini=0;
int dist=0;
int pus =0;



void running_mode(){
    tft.fillRoundRect(2,50,315,185,5, TFT_RED);
    tft.setTextSize(3);
    tft.setTextColor(TFT_WHITE);
    tft.drawString("Running Mode",30,55);
    tft.drawString("________________________",3,60);
}

void exit_running(){
  spr.fillSprite(TFT_WHITE);
  spr.fillRoundRect(2,2,315,45,5, TFT_BLUE);
  spr.fillRoundRect(2,50,315,185,5, TFT_GREEN);
  spr.setTextColor(TFT_WHITE);
  spr.setTextSize(3);
  spr.drawString("1. Smart Motor", 3,10);
  spr.drawString(" Training Mode", 30,55 );
  spr.drawString("________________________",3,60);
  spr.setTextSize(2);
  spr.drawString("Number of Training", 50,110);
  spr.drawRoundRect(80,130,165,80,20, TFT_WHITE);
  spr.setTextSize(5);
  spr.drawString("/10",147,150);
}

   

void setup() {
  Serial.begin(115200);
  myservo.attach(D1);

  tft.begin();
  tft.setRotation(3);
  
  spr.createSprite(TFT_HEIGHT, TFT_WIDTH);
  spr.fillSprite(TFT_WHITE);
  spr.fillRoundRect(2,2,315,45,5, TFT_BLUE);
  spr.fillRoundRect(2,50,315,185,5, TFT_GREEN);
  spr.setTextColor(TFT_WHITE);
  spr.setTextSize(3);
  spr.drawString("1. Smart Motor", 3,10);
  spr.drawString(" Training Mode", 30,55 );
  spr.drawString("________________________",3,60);
  spr.setTextSize(2);
  spr.drawString("Number of Training", 50,110);
  spr.drawRoundRect(80,130,165,80,20, TFT_WHITE);
  spr.setTextSize(5);
  spr.drawString("/10",147,150);
  
  
   pinMode(WIO_KEY_A, INPUT);
   pinMode(WIO_5S_RIGHT, INPUT);
   pinMode(WIO_5S_LEFT, INPUT);
   pinMode(WIO_BUZZER, OUTPUT);
   pinMode(WIO_LIGHT, INPUT);
   pinMode(WIO_5S_DOWN, INPUT);
   pinMode(WIO_5S_PRESS, INPUT);
}


void loop() {
  if(digitalRead(WIO_5S_LEFT) == LOW) {
    pos = pos - 5;
    myservo.write(pos);
    
    delay(100);
    pos = max(0, min(pos,180));
    Serial.println(pos);
  }
   else if(digitalRead(WIO_5S_RIGHT) == LOW) {
     pos=pos+5 ;
     myservo.write(pos);
     
     delay(100);
     pos = max(0, min(pos,180));
     Serial.println(pos);
  }

if(digitalRead(WIO_5S_PRESS) == LOW){
  if(count<10){
    
    brightness=analogRead(WIO_LIGHT);
    training[count][0] = pos;
    training[count][1] = brightness;
        Serial.print(count);
        Serial.print("\n");
        Serial.print(pos);
        Serial.print("\n");
        Serial.print(brightness);
        Serial.print("\n");
       analogWrite(WIO_BUZZER, 128);
      count++;
      delay(100);
      analogWrite(WIO_BUZZER, 0);
      while(digitalRead(WIO_5S_PRESS));
       spr.setCursor(90, 150);
       spr.fillRect(85,150,60,40, TFT_GREEN);
       spr.print(count);
       
      delay(500);
    
  }
  else{
      running_mode();
                
      analogWrite(WIO_BUZZER, 128);
      delay(500);
      analogWrite(WIO_BUZZER, 0);
      delay(100);
      analogWrite(WIO_BUZZER, 128);
      delay(500);
      analogWrite(WIO_BUZZER, 0);
      delay(100);
      analogWrite(WIO_BUZZER, 128);
      delay(500);
      analogWrite(WIO_BUZZER, 0);

      Serial.print("in run mode");
      for(int i=0;i<10;i++){
        Serial.print(i);
        Serial.print("\n");
        Serial.print(training[i][0]);
        Serial.print("\n");
        Serial.print(training[i][1]);
        Serial.print("\n");
 }
 while(digitalRead(WIO_5S_PRESS)){ 

  
  
        brightness = analogRead(WIO_LIGHT);
        mini=1000;
        pus=0;
        for (int i=0;i<10;i++){
          dist=abs(brightness - training[i][1]);
          if (dist<mini){
            mini=dist;
            pus=training[i][0];
            
          }
        }
       myservo.write(pus);
       delay(100);
      }
      count=0;
      exit_running();
      
    }
  }
  
  spr.pushSprite(0,0);
  delay(50);
}
