#include <Arduino.h>
#include "peripheral.h"

#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

class serialController {
  private:
    uint8_t dev;
    int cnt;
    peripheral** payloadArr;
    unsigned long lastMillis;
  public:
    serialController();
    void addPeripheral(peripheral* periph);
    int getCnt();
    peripheral* retPeriph(int cnt);
    int printMessage();
    void sendPeriph();
    int debugPeriphs();
    unsigned long getLastMillis();
    void updateMillis(unsigned long currMillis);
    void checkSerial();
};

#endif
