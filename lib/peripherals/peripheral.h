#include <Arduino.h>

#ifndef PERIPHERAL_H
#define PERIPHERAL_H

class peripheral {
  private:
    static uint8_t prevID;
  protected:
    uint8_t id;
    uint8_t device;
    uint8_t mode;
  public:
    peripheral();
    uint8_t fetchID();
};

#endif
