#include "serialInterface.h"
#include "peripheral.h"

#ifndef TEMPSENSOR_H
#define TEMPSENSOR_H

class tempSensor : public peripheral {
    private:
        uint8_t analogPin;
        int tempReading;
        float temperature;
    public:
        tempSensor(uint8_t analogPin, serialController* seri);
        void readTemp();
        float retTemp();
        void debugAction(uint8_t debugMode);    
};

#endif