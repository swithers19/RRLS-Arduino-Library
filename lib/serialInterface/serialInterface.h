#include <Arduino.h>
#include <SoftwareSerial.h>
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
    unsigned int duration[2];
    debugData* ddStore;
    SoftwareSerial* mySerial;
  public:
    serialController(SoftwareSerial* ms);
    void addPeripheral(peripheral* periph);
    int getCnt();
    bool validateID(debugData* ddStore,int inVal);
    peripheral* retPeriph(int cnt);
    void sendPeriph();
    bool debugPeriphs(int inVal);
    void checkSerial();
    void debugMode(int debugCnt);
};

#endif

