#include <Arduino.h>
#include "ardResp.h"

//Led initialisation
led myLed(4, serialESP); 
led myLed1(5, serialESP);
//Ultrasonic sensor initialisation
ultraRange sensor(9, 8, serialESP);
tempSensor myT(2, serialESP);

void setup() {
  mySerial.begin(9600);
  Serial.begin(9600);
}

void loop() {
  myLed.turnOn();
  myLed1.turnOff();
  sensor.readRange();
  
  myT.readTemp();
  Serial.println(myT.retTemp());

  while (mySerial.available()>0) { //Send to ESP32
    serialESP->checkSerial();
  }

}








