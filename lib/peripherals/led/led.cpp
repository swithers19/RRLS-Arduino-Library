#include "led.h"

//Led Constructor
led::led(uint8_t iPin, serialController* seri) : peripheral() {
  device = 1;
  newID();
  mode = 1;
  pinCnt = 1;
  senRead = 0;
  pinArr = new uint8_t[4]{iPin, 0, 0, 0};
  seri->addPeripheral(this);
  pinMode(iPin, OUTPUT);
}

//Pin turnOn
void led::turnOn() {
  digitalWrite((pinArr[0]), HIGH);
  mode = 2;
}

void led::turnOff() {
  digitalWrite((pinArr[0]), LOW); 
  mode = 1;
}

void led::debugAction(uint8_t debugMode){
  if (debugMode == 1) {
    turnOff();
  }
  else if (debugMode == 2) {
    turnOn();
  }
}
