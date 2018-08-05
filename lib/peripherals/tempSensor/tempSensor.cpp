#include "tempSensor.h"

tempSensor::tempSensor(uint8_t nanalogPin, serialController* seri) :peripheral() {
    analogPin = nanalogPin;
    //Configuring settings for ultrasonic
    device = 3;
    newID();
    mode = 1;
    pinCnt = 1;
    senRead = 0;
    //Pin Assignment
    pinArr = new uint8_t[4]{analogPin, 0, 0, 0};
    seri->addPeripheral(this);
}

void tempSensor::readTemp(){
    tempReading = analogRead(analogPin);
}

float tempSensor::retTemp(){
     float voltage = tempReading * 5.0;
    voltage /= 1024.0;
    temperature = (voltage - 0.5) * 100 ; 
    return temperature; 
}

void tempSensor::debugAction(uint8_t debugMode) {
    if (debugMode == 1) {
        readTemp();
    }
}