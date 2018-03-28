#include "serialInterface.h"
#include "peripheral.h"

#ifndef ULTRARANGE_H
#define ULTRARANGE_H

class ultraRange : public peripheral {
    private:
        uint8_t trigPin;
        uint8_t echoPin;
        int distance;
    public:
        ultraRange(uint8_t trigPin, uint8_t echoPin, serialController* seri);
        void readRange();
        int retDistance();
        void debugAction(uint8_t debugMode);    
};

#endif