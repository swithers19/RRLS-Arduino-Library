#include "peripheral.h"

uint8_t peripheral::nextId;         //Create first instance of nextID, used for unique ID's

//Fetches device ID
uint8_t peripheral::fetchID() {
  return id;
}

//Prints to serial each parameter of a peripheral
void peripheral::printPeriph() {
  if (Serial) {
    Serial.println(device, HEX);
    Serial.println(id, HEX);
    Serial.println(mode, HEX);
    for (int i = 0; i < 4; i++) {
      Serial.println(pinArr[i], HEX);
    }
  }
}

//Generates a peripheral new ID
void peripheral::newID() {
  nextId++;
  id = nextId;
}

void peripheral::setMode(uint8_t debugMode) {
  mode = debugMode;
}
