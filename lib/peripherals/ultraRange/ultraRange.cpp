#include "ultraRange.h"
//Ultrasonic Sensor Constructor
ultraRange::ultraRange(uint8_t ntrigPin, uint8_t nechoPin, serialController* seri) :peripheral() {
    trigPin = ntrigPin;
    echoPin = nechoPin;
    //Configuring settings for ultrasonic
    device = 2;
    newID();
    mode = 1;
    pinCnt = 2;
    senRead = 0;
    //Pin Assignment
    pinArr = new uint8_t[4]{trigPin, echoPin, 0, 0};
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    seri->addPeripheral(this);
}
void ultraRange::readRange(){
    int duration =  0;
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculating the distance
    senRead = duration*0.034/2;
}

int ultraRange::retDistance(){
    return senRead; 
}

void ultraRange::debugAction(uint8_t debugMode) {
    if (debugMode == 1) {
        readRange();
    }
}