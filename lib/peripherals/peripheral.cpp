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
void peripheral::writePeriph(SoftwareSerial* mySerial) {
  if (mySerial) {
    mySerial->write((byte)device);
    mySerial->write((byte)id);
    mySerial->write((byte)mode);
    mySerial->write((senRead>>8) & 0xFF);
    mySerial->write(senRead & 0xFF);
    for (int i = 0; i < 4; i++) {
      mySerial->write((byte)pinArr[i]);
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


