#include "serialInterface.h"

serialController::serialController() {
  this->payloadArr = new peripheral*[15];
  this->cnt = 0;
}

void serialController::addPeripheral(peripheral* periph) {
  this->payloadArr[(this->cnt)] = periph;
  this->cnt++;
  if ((this->cnt) >14) {
  }
}

int serialController::getCnt() {
  return this->cnt;
}
