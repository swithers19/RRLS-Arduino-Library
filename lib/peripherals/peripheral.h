#include <Arduino.h>

#ifndef PERIPHERAL_H
#define PERIPHERAL_H

class peripheral {
  protected:
    static uint8_t nextId;
    uint8_t id;
    uint8_t device;
    uint8_t mode;
    uint8_t pinCnt;
    uint8_t* pinArr;
  public:
    uint8_t fetchID();
    void printPeriph();
    void newID();
    void setMode(uint8_t debugMode);
};
#endif
