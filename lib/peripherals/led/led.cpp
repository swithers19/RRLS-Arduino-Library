#include "led.h"

//Led Constructor
led::led(int iPin, serialController* seri) : peripheral() {
  pin = iPin;
  this->device = 1;
  this->id = 22;
  seri->addPeripheral(this);
}

//Pin turnOn
void led::TurnOn() {
  digitalWrite(pin, HIGH);
  ledOn == 1;
}
