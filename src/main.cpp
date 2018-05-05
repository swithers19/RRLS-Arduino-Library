#include <Arduino.h>
#include "ardResp.h"

//Led initialisation
led myLed(5, serialESP);
ultraRange sensor(9, 8, serialESP);

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);

}

void loop() {
  myLed.turnOn();
  sensor.readRange();
  Serial.println(sensor.retDistance());
  while (mySerial.available()>0) {
    serialESP->checkSerial();
  }
}






