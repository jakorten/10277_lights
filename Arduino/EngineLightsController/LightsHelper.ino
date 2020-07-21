/*
    J.A. Korten
    LEGuanO.nl
    V1.0 July 20, 2020

    Engine Light Controller

    Use: https://github.com/SpenceKonde/megaTinyCore/blob/master/megaavr/extras/ATtiny_x16.md
    Helper for Lights

*/

#define lights_dual_a1 15
#define lights_dual_a2 0

#define lights_dual_b1 16
#define lights_dual_b2 14

#define lights_dual_c1 1
#define lights_dual_c2 3

#define light_single   2  // PA6


void activateRightLight() {
  digitalWrite(light_single, HIGH);
}

void deactivateRightLight() {
  digitalWrite(light_single, LOW);
}

void initLights() {
  pinMode(lights_dual_a1, OUTPUT);
  pinMode(lights_dual_a2, OUTPUT);
  pinMode(lights_dual_b1, OUTPUT);
  pinMode(lights_dual_b2, OUTPUT);
  pinMode(lights_dual_c1, OUTPUT);
  pinMode(lights_dual_c2, OUTPUT);
  pinMode(light_single, OUTPUT);
}

void allLightsOff() {
  digitalWrite(lights_dual_a1, LOW);
  digitalWrite(lights_dual_a2, LOW);
  digitalWrite(lights_dual_b1, LOW);
  digitalWrite(lights_dual_b2, LOW);
  digitalWrite(lights_dual_c1, LOW);
  digitalWrite(lights_dual_c2, LOW);
  digitalWrite(light_single,   LOW);
}

void setLeads(byte lead1, byte lead2, byte command) {
  if (command == lightOn) {
    digitalWrite(lead1, LOW);
    digitalWrite(lead2, HIGH);
  } else {
    digitalWrite(lead1, LOW);
    digitalWrite(lead2, LOW);
  }
}

void setLead(byte lead, byte command) {
  if (command == lightOn) {
    digitalWrite(lead, HIGH);
  } else {
    digitalWrite(lead, LOW);
  }
}

void topLightRed(byte command) {
  setLeads(lights_dual_b1, lights_dual_b2, command);
}

void topLightWhite(byte command) {
  setLeads(lights_dual_b2, lights_dual_b1, command);
}

void leftLightRed(byte command) {
  setLeads(lights_dual_a1, lights_dual_a2, command);
}

void leftLightWhite(byte command) {
  setLeads(lights_dual_a2, lights_dual_a1, command);
}

void rightLightRed(byte command) {
  setLeads(lights_dual_c1, lights_dual_c2, command);
}

void rightLightWhite(byte command) {
  setLeads(lights_dual_c2, lights_dual_c1, command);
}

void setCabinLight(byte command) {
  setLead(light_single, command);
}

void allLightsWhite(byte command) {
  topLightWhite(command);
  leftLightWhite(command);
  rightLightWhite(command);
}

void allLightsRed(byte command) {
  topLightRed(command);
  leftLightRed(command);
  rightLightRed(command);
}
