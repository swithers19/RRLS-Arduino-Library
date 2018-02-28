#include <Arduino.h>
#include "led.h"

serialController* x = new serialController();
led myLed(5, x);

void setup() {
  Serial.begin(115200);

    // put your setup code here, to run once:
}

void loop() {
  Serial.print(myLed.fetchID(), HEX);
  delay(5000);
    // put your main code here, to run repeatedly:
}
