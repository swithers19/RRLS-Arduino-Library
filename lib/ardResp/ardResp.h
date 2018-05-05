#include <SoftwareSerial.h>

#include "serialInterface.h"
#include "peripheral.h"
#include "led.h"
#include "ultraRange.h"

SoftwareSerial mySerial(10, 11); // RX, TX
serialController* serialESP = new serialController(&mySerial);
