#include "serialInterface.h"

//Initialise the controller with room for 15 peripherals
serialController::serialController(SoftwareSerial* ms) 
{
  this->cnt = 0;
  this->payloadArr = new peripheral*[15];
  this->ddStore = 0;
  dev = 12;
  lastMillis = millis();
  this->mySerial = ms;
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
  mySerial->print(this->cnt);
  return this->cnt;
}

//Checks serial and whether we need to send or recieve data
void serialController::checkSerial() 
{
    static bool debugStart = false;

    while (mySerial->available()) {
        int inChar = mySerial->read();               // get the new byte:
        if (inChar == '/') {
            this->sendPeriph();                 //Send configuration data
        }
        else if (inChar == '&' && debugStart == false) {
            //Start debug control process
            debugStart = true;
            ddStore = new debugData[getCnt()];    //Creating data store for debugging data
            Serial.println("Setting debugStart");
        }
        else if (debugStart == true) {
            debugStart = this->debugPeriphs(inChar); 
        }
    }
}

//Read in debug values
bool serialController::debugPeriphs(int inVal) {
    static int i = 0;
    static int periCtr = 0;
    bool debugStatus = true;
    bool errorFlag = false;

    if (inVal == DEBUG_TERM) {
        //errorFlag = peripheral list complete
        debugStatus = false;
        if (errorFlag == false) {
            Serial.println("Debug complete!");
            debugMode(periCtr);      //set debug parameters
        }
        periCtr = 0;
        i = 0;
        duration[0] = duration[1] = 0;
    }
    else {
        if (i < 2) {
            this->duration[i] = inVal;
            Serial.print("duration byte ");
            Serial.println(inVal, DEC);
            i++;
        }
        else if (i >= 2) {
            if ((i % 2 == 0) && (inVal != DEBUG_TERM)) {
                errorFlag = validateID(&ddStore[periCtr], inVal);  //Error validation and 
                Serial.println(errorFlag);
                i++;
            }  
            else if((i % 2 == 1) && (inVal != DEBUG_TERM)) {
                ddStore[periCtr].mode = inVal;
                Serial.print("Mode: ");
                Serial.println(inVal, DEC);
                periCtr++;  //Increment number of peripherals
                i++;
            }
        }
        if (errorFlag) {
            debugStatus = false;
            errorFlag = false;
            i = 0;
            periCtr = 0;
        }

    }
    return debugStatus;
}

//Ensures ID is valid, spits error if not correct
bool serialController::validateID(debugData* ddStore,int inVal) {
    bool ret = true;
    for(int i = 0; i<getCnt(); i++) {
        if(inVal == this->payloadArr[i]->fetchID()) {
            ddStore->devPtr = this->payloadArr[i];
            ddStore->id = inVal;
            Serial.print("ID is ");
            Serial.println(ddStore->id);
            ret = false;
        }
    }
    return ret;
}

//Function in charge of manipulating peripherals in debug
void serialController::debugMode(int debugCnt)
{
    unsigned long start = millis();
    unsigned int dur = (duration[0]<<8) +duration[1]; 
    mySerial->print('~++');
    while (dur > (int)(millis() - start)) {
        //Set each peripheral to desired mode
        for (int i = 0; i<debugCnt; i++) {
            ddStore[i].devPtr->debugAction(ddStore[i].mode);
        }
        //this->sendPeriph();
    }

    //Reset back to normal operation
    for (int i = 0; i<debugCnt; i++) {
        ddStore[i].devPtr->debugAction(ddStore[i].devPtr->fetchMode());
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
    mySerial->print('^');
    mySerial->write(cnt);
    if ((millis() - (this->lastMillis)) > 50 ) {
        for (int i = 0; i < cnt; i++) {
            payloadArr[i]->writePeriph(mySerial);
            if (i < (cnt - 1)) {
                //mySerial->print('\n');
            }
        }
        mySerial->print("++"); 
    }
    this->lastMillis = millis();
}





