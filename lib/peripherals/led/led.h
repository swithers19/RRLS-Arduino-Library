#include <Arduino.h>

#include "serialInterface.h"
#include "peripheral.h"

#ifndef LED_H
#define LED_H

class led : public peripheral
{
  private:
    int pin;
    bool ledOn;
  public:
    led(int iPin, serialController* seri);        //Pin constructor function
    void TurnOn();        //Pin turnOn
};

#endif
