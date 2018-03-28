#include <Arduino.h>
#include "peripheral.h"

#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

const uint8_t DEBUG_TERM = 244;

struct debugData {   
        int id;
        int mode;
        peripheral* devPtr;
};

class serialController {
  private:
    uint8_t dev;
    int cnt;
    peripheral** payloadArr;
    unsigned long lastMillis;
    debugData* ddStore;
  public:
    serialController();
    void addPeripheral(peripheral* periph);
    int getCnt();
    bool serialController::validateID(debugData* ddStore,int inVal);
    peripheral* retPeriph(int cnt);
    int printMessage();
    void sendPeriph();
    bool debugPeriphs(int inVal);
    void checkSerial();
};

#endif

