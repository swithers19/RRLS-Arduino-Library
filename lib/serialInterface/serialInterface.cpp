#include "serialInterface.h"

//Initialise the controller with room for 15 peripherals
serialController::serialController() 
{
  this->cnt = 0;
  this->payloadArr = new peripheral*[15];
  this->ddStore = 0;
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
    static bool debugStart = false;
    uint8_t errorFlag = 0;
    //if it hasn't been checked for a while, read
    if ((millis() - (this->lastMillis)) > 50 ) {
        while (Serial.available()) {
            int inChar = Serial.read();               // get the new byte:
            if (inChar == 97) {
                  this->sendPeriph();                 //Send configuration data
            }
            else if (inChar == 98 && debugStart == false) {
                //Start debug control process
                debugStart = true;
                ddStore = new debugData[getCnt()];    //Creating data store for debugging data
            }
            else if (debugStart == true && inChar != 98) {
                debugStart = this->debugPeriphs(inChar); 
            }
        }
      this->lastMillis = millis();
    }
}

//Read in debug values
bool serialController::debugPeriphs(int inVal) {
    static int i = 0;
    static int periCtr = 0;
    bool debugStatus = true;
    bool errorFlag = 0;
    int duration[2];

    if (i < 2) {
        duration[i] = inVal;
        Serial.println(inVal, DEC);
        i++;
    }
    else if (i > 2) {
        if ((i % 2 == 0) && (inVal != DEBUG_TERM)) {
            errorFlag = validateID(&ddStore[i/2], inVal);  //Error validation and 
            Serial.println(ddStore[0].id, DEC);
            i++;
        }  
        else if((i % 2 == 1) && (inVal != DEBUG_TERM)) {
            ddStore[periCtr].mode = inVal;
            Serial.println(inVal, DEC);
            i++;
        }
    }
    else if (inVal == DEBUG_TERM) {
        debugStatus = false;
        //error validate
    }
    if (errorFlag != 0) {
        debugStatus = false;
    }
    else if (inVal == DEBUG_TERM && errorFlag == 0) {
        //set debug parameters
    }
    return debugStatus;
}

bool serialController::validateID(debugData* ddStore,int inVal) {
    for(int i = 0; i<getCnt(); i++) {
        if(inVal == this->payloadArr[i]->fetchID()) {
          ddStore->devPtr = this->payloadArr[i];
          ddStore->id = inVal;
        }
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

//A test message to check serial functionality
int serialController::printMessage()
{
  Serial.println("Hello Hello");
  return 1;
}




