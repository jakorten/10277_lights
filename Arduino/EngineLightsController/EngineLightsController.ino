/*
 *  J.A. Korten
 *  LEGuanO.nl
 *  V1.0 July 20, 2020
 *  
 *  Engine Light Controller
 *  Uses: https://github.com/xukangmin/TinyCore
 */



// i2c op SDA_2 / SCL_3
#include "settings.h"

void setup() {
  initTwoWire(frontModule);
  initLights();
  activateRightLight();
}

void loop() {
  
}
