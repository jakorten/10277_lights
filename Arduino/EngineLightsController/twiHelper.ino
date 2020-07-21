/*
    J.A. Korten
    LEGuanO.nl
    V1.0 July 20, 2020

    Engine Light Controller
    Uses: https://github.com/xukangmin/TinyCore

    i2c control
*/

#include <Wire.h>

void initTwoWire(byte moduleAddress) {
  Wire.begin(moduleAddress);       // join i2c bus with moduleAddress
  Wire.onReceive(receiveEvent);    // register event
}

void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all command bytes
    byte lampCode = Wire.read(); // receive first byte light selector
    if (lampCode == allOff) {
      allLightsOff();
    } else if (howMany >= 2) {
      byte commandCode = Wire.read(); // receive second byte as command
      switch (lampCode) {
        case topRed:
          topLightRed(commandCode);
          break;
        case topWhite:
          topLightWhite(commandCode);
          break;
        case threeWhites:
          allLightsWhite(commandCode);
          break;
        case leftRed:
          leftLightRed(commandCode);
          break;
        case leftWhite:
          leftLightWhite(commandCode);
          break;
        case rightRed:
          rightLightRed(commandCode);
          break;
        case rightWhite:
          rightLightWhite(commandCode);
          break;
        case cabinLight:
          setCabinLight(commandCode);
          break;
        case threeReds:
          allLightsRed(commandCode);
          break;
      }
    }
  }
}
