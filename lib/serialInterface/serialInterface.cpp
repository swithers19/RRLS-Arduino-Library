#include "serialInterface.h"

//Initialise the controller with room for 15 peripherals
serialController::serialController() 
{
  this->payloadArr = new peripheral*[15];
  this->cnt = 0;
  dev = 12;
  lastMillis = millis();
}

//Process to add a peripheral, and add it to the index
void serialController::addPeripheral(peripheral* periph) 
{
  this->payloadArr[(this->cnt)] = periph;
  this->cnt++;
}

//Keeps track of peripheral amount
int serialController::getCnt() 
{
  return this->cnt;
}

//Checks serial and whether we need to send or recieve data
void serialController::checkSerial() 
{
  if ((millis() - (this->lastMillis)) > 50 ) {
  //if it hasn't been checked for a while, read
    while (Serial.available()) {
      // get the new byte:
      int inChar = Serial.parseInt();
      if (inChar == 120) {
        this->sendPeriph();
      }
      else if (inChar == 140) {
        this->debugPeriphs();
      }
    }
    this->lastMillis = millis();
  }
}

//Returns a peripheral pointer based on the index provided
peripheral* serialController::retPeriph(int cnt) 
{
  return this->payloadArr[cnt];
}

//Sends to serial all the data of each peripheral
void serialController::sendPeriph() 
{
  for (int i = 0; i < cnt; i++) {
    Serial.print("Device ");
    Serial.println(i);
    payloadArr[i]->printPeriph();
  }
}

//Read in debug values
int serialController::debugPeriphs() {
  uint8_t incomByte = 0, uniqueID = 0, mode = 0;
  int i = 0;
  uint8_t* dev = new uint8_t[2] {};

  while (Serial.available() > 0) {
    if (i<2) {
      dev[i] = Serial.read();
    }
    else {
      if (i % 2 == 0 && i != 0) {
        uniqueID = Serial.read();   
      }
      else if (i % 2 == 1) {
        mode = Serial.read();
        this->payloadArr[uniqueID]->setMode(mode);

      }
      else {
        //catch error, something has gone wrong, exit, look for start bit again
      }
    }
    i++;
  }
  return 0;
}


//A test message to check serial functionality
int serialController::printMessage()
{
  Serial.println("Hello Hello");
  return 1;
}