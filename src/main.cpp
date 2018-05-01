#include <Arduino.h>
#include "ardResp.h"

SoftwareSerial mySerial(10, 11); // RX, TX

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
  //mySerial.print("ayyyyo");
  while (Serial.available()>0) {
    char in = Serial.read();
    Serial.print(in);
  }
}

//Serial event checks serial rx buffer everyy loop cycle
/*void serialEvent() {
  serialESP->checkSerial();
}*/






