#include <Arduino.h>

#include "serialInterface.h"
#include "peripheral.h"

#ifndef LED_H
#define LED_H

class led : public peripheral
{
  private:
    bool ledOn;
    int* ledPrint;
  public:
    led(uint8_t iPin, serialController* seri);        //Pin constructor function
    void turnOn();        //Pin turnOn
    void turnOff();
    int retMode();
};

#endif
