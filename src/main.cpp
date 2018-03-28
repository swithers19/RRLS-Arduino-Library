#include <Arduino.h>
#include "ardResp.h"

//Led initialisation
led myLed(5, serialESP);
ultraRange sensor(9, 8, serialESP);

void setup() {
  Serial.begin(115200);
  
}

void loop() {
  myLed.turnOn();
  //sensor.readRange();
  //Serial.println(sensor.retDistance());
}



//Serial event checks serial rx buffer everyy loop cycle
void serialEvent() {
  serialESP->checkSerial();
}






