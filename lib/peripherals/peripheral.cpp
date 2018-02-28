#include "peripheral.h"

peripheral::peripheral() {
  this->id = 0;
}

uint8_t peripheral::fetchID() {
  return this->id;
}
