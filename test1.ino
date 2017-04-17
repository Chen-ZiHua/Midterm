#include "SevSeg.h"
SevSeg sevseg;

void setup() {
  Serial.begin(9600);
  Serial.println("27 04050015 04052502");
  byte numDigits = 4; 
  byte digitPins[] = {5, 4, 3, 2}; 
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13}; 
  sevseg.begin(COMMON_CATHODE, numDigits,digitPins,segmentPins); 
}
void loop() {
  int i;
  if(Serial.available())
  {
      i=Serial.parseInt();
      if(i<=9999 && i>0)
       {
          Serial.println(i);
          sevseg.setNumber(i);
          sevseg.refreshDisplay();
        }
      else
        {
          Serial.println("range error");
        }
  }
    else
      {
  sevseg.refreshDisplay();
  
  }
}

