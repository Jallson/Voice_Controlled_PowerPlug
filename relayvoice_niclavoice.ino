#include "NDP.h"
#include <Wire.h>

void sendit(char* label) {

  if (strcmp(label, "NN0:one") == 0) {
    Serial.println(label);
    NDP.noInterrupts();
    nicla::leds.begin();
    nicla::leds.setColor(blue);
    Wire.beginTransmission(9);
    Wire.write(1);
    Wire.endTransmission();
    delay(200);
    nicla::leds.end();
    NDP.interrupts();
  }
  if (strcmp(label, "NN0:two") == 0) {
    Serial.println(label);
    NDP.noInterrupts();
    nicla::leds.begin();
    nicla::leds.setColor(blue);
    Wire.beginTransmission(9);
    Wire.write(2);
    Wire.endTransmission();
    delay(200);
    nicla::leds.end();
    NDP.interrupts();
  }
  if (strcmp(label, "NN0:three") == 0) {
    Serial.println(label);
    NDP.noInterrupts();
    nicla::leds.begin();
    nicla::leds.setColor(blue);
    Wire.beginTransmission(9);
    Wire.write(3);
    Wire.endTransmission();
    delay(200);
    nicla::leds.end();
    NDP.interrupts();
  }
  if (strcmp(label, "NN0:four") == 0) {
    Serial.println(label);
    NDP.noInterrupts();
    nicla::leds.begin();
    nicla::leds.setColor(blue);
    Wire.beginTransmission(9);
    Wire.write(4);
    Wire.endTransmission();
    delay(200);
    nicla::leds.end();
    NDP.interrupts();
  }
  if (strcmp(label, "NN0:on") == 0) {
    Serial.println(label);
    NDP.noInterrupts();
    nicla::leds.begin();
    nicla::leds.setColor(green);
    Wire.beginTransmission(9);
    Wire.write(5);
    Wire.endTransmission();
    delay(200);
    nicla::leds.end();
    NDP.interrupts();
  }
  if (strcmp(label, "NN0:off") == 0) {
    Serial.println(label);
    NDP.noInterrupts();
    nicla::leds.begin();
    nicla::leds.setColor(red);
    Wire.beginTransmission(9);
    Wire.write(6);
    Wire.endTransmission();
    delay(200);
    nicla::leds.end();
    NDP.interrupts();
  }
}

/**
  Blinking green LED when called. 
*/
void ledGreenOn() {
  nicla::leds.begin();
  nicla::leds.setColor(green);
  delay(200);
  nicla::leds.setColor(off);
  nicla::leds.end();
}

/**
  Infinite blinking red LED when a system error occurred. 
*/
void ledRedBlink() {
  while (1) {
    nicla::leds.begin();
    nicla::leds.setColor(red);
    delay(200);
    nicla::leds.setColor(off);
    delay(200);
    nicla::leds.end();
  }
}

/**
  Blinking blue LED when called (for BLE connection). 
*/
void ledBlueBlink() {

  for (int i = 0; i <= 2; i++) {
    nicla::leds.begin();
    nicla::leds.setColor(blue);
    delay(200);
    nicla::leds.setColor(off);
    delay(200);
    nicla::leds.end();
  }
}

/**
  Main section setup
*/
void setup() {

  Wire.begin();
  Serial.begin(115200);

  // Nicla System setup
  nicla::begin();
  nicla::disableLDO();
  nicla::enableCharge(100);  // enabling the battery charger
  nicla::leds.begin();

  // Neural Decision Processor callbacks setup
  NDP.onError(ledRedBlink);
  NDP.onMatch(sendit);
  NDP.onEvent(ledGreenOn);

  Serial.println("Loading synpackages");

  // Neural Decision Processor firmware and ML model files loading
  NDP.begin("mcu_fw_120_v91.synpkg");
  NDP.load("dsp_firmware_v91.synpkg");
  NDP.load("ei_model.synpkg");
  Serial.println("packages loaded");
  NDP.getInfo();
  Serial.println("Configure mic");
  NDP.turnOnMicrophone();

  nicla::leds.end();

  NDP.interrupts();
}

void loop() {
  
}