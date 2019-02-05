#include <EEPROM.h>
#include "LowPower.h"

int num = EEPROM.read(0);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(EEPROM.read(0));
}

void loop() {
  if (EEPROM.read(0) == 0) {
    num = num + 1;
    EEPROM.write(0, num);
    delay(10);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
  if (EEPROM.read(0) == 1) {
    num = num + 1;
    EEPROM.write(0, num);
    delay(10);
    LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
  if (EEPROM.read(0) == 2) {
    num = num + 1;
    EEPROM.write(0, num);
    delay(10);
    LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
  }
  if (EEPROM.read(0) == 3) {
    num = num + 1;
    EEPROM.write(0, num);
    delay(10);
    LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
  }
  if (EEPROM.read(0) > 3) {
    num = 0;
    EEPROM.write(0, num);
    delay(10);
    Serial.println(analogRead(0));
    delay(1000);
  }
}

void memoria() {
  EEPROM.write(0, 0);
}
