#include <Arduino.h>
#include <SoftwareSerial.h>
#ifndef PERIPHERAL_H
#define PERIPHERAL_H

class peripheral {
  protected:
    static uint8_t nextId;
    uint8_t id;
    uint8_t device;
    uint8_t mode;
    uint16_t senRead;
    uint8_t pinCnt;
    uint8_t* pinArr;
  public:
    uint8_t fetchID();
    void sendPeriph();
    void printPeriph(SoftwareSerial* mySerial);
    void newID();
    uint8_t fetchMode();
    virtual void debugAction(uint8_t debugMode) = 0; //Pure virtual class, objects use this to control
};
#endif
