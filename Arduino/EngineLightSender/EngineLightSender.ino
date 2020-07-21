// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>
#include "settings.h"

void setup() {
  Wire.begin(); // join i2c bus (address optional for master)
  Serial.begin(115200);
  delay(1000);
  Wire.beginTransmission(frontModule);
  int error = Wire.endTransmission();
  int i = 0;
  while (error != 0) {
    Wire.beginTransmission(frontModule);
    error = Wire.endTransmission();
    Serial.print(".");
    delay(100);
    i++;
    if (i > 150) {
      Serial.println();
      i = 0;
    }
  }
  Serial.println();
  Serial.println("Lights found at 0x01");
}

byte x = 0;

void loop() {

  sendLightCommand(frontModule, x, lightOn);

  x++;
  if (x > 9) {
    x = 0;
  }
  delay(500);
}

void sendLightsOff(byte address) {
  Wire.beginTransmission(address); // transmit to device #8
  Wire.write(allOff);              // sends one byte
  int error = Wire.endTransmission();    // stop transmitting
  if (error == 0) {
    Serial.println("OK");
  }
}

void sendLightCommand(byte address, byte light, byte command) {
  Wire.beginTransmission(address); // transmit to device #8
  Wire.write(light);              // sends one byte
  Wire.write(command);            // sends one byte
  int error = Wire.endTransmission();         // stop transmitting
  if (error == 0) {
    Serial.println("OK");
  }
}
