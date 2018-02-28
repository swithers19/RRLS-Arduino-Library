#include "peripheral.h"

#ifndef SERIALINTERFACE_H
#define SERIALINTERFACE_H

class serialController {
  private:
    uint8_t dev;
    int cnt;
    peripheral** payloadArr;
  public:
    serialController();
    void addPeripheral(peripheral* periph);
    int getCnt();
};

#endif
