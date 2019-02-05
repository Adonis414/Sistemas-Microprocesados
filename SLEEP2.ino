#include <EEPROM.h>

#include <MsTimer2.h>
#include <avr/sleep.h>
#include <avr/power.h>

int cont = 0;
void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000, conteo);
  MsTimer2::start();

  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  sleep_enable();
}

void loop() {
  // put your main code here, to run repeatedly:
  sleep_disable();
    delay(20);

}


void conteo() {
  if (cont < 3) {
    cont++;
    Serial.println(cont);
      } else {    
    Serial.println(analogRead(0));
    Serial.flush();
    cont = 0;
    delay(20);
    sleep_mode();
  }
}
