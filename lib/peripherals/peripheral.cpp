#include "peripheral.h"

uint8_t peripheral::nextId;         //Create first instance of nextID, used for unique ID's

//Fetches device ID
uint8_t peripheral::fetchID() {
  return id;
}

uint8_t peripheral::fetchMode() 
{
    return mode;
}

//Sends peripherals in byte format
void peripheral::sendPeriph() {
  if (Serial) {
    Serial.write(device);
    Serial.write(id);
    Serial.write(mode);
    Serial.write(senRead);
    for (int i = 0; i < 4; i++) {
      Serial.write(pinArr[i]);
    }
  }
}

//Prints to serial each parameter of a peripheral
void peripheral::printPeriph(SoftwareSerial* mySerial) {
  if (Serial) {
    mySerial->print(device);
    mySerial->print(id);
    mySerial->print(mode);
    mySerial->print("'");
    mySerial->print(senRead);
    mySerial->print("'");
    for (int i = 0; i < 4; i++) {
      mySerial->print(pinArr[i]);
    }
  }
}

//Generates a peripheral new ID
void peripheral::newID() {
  nextId++;
  id = nextId;
}


