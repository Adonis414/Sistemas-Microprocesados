#include "LowPower.h"
String tiempo;
int t;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
 if(Serial.available()>=0){
  Serial.println("Ingrese el tiempo de sleep en segundos: 1S, 2S, 4S, 8S");
  delay(5000);
  tiempo =Serial.readString();
  t=tiempo.toInt();  
 
 if(t=1)LowPower.powerDown(SLEEP_1S, ADC_OFF, BOD_OFF);
 if(t=2)LowPower.powerDown(SLEEP_2S, ADC_OFF, BOD_OFF);
 if(t=4)LowPower.powerDown(SLEEP_4S, ADC_OFF, BOD_OFF);
 if(t=8)LowPower.powerDown(SLEEP_8S, ADC_OFF, BOD_OFF);
  }
}
