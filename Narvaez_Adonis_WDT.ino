#include <MsTimer2.h>
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include <avr/wdt.h>  //avr
/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Adonis Narváez
   Fecha: 22-01-2019

   Temas:
   1.-Realizar un programa que permita que el conversor análogo
   digital configure al perro guardían a 10,20,30 y 40 segundos.
   Este proceso se visualiza en una lcd.
*/

LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //pines para conectar el lcd
int dato;
int j = 0;
int i = 0;
int var = 10;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  Serial.println("Reiniciado");
  wdt_disable();


}

void loop() {
  dato = map(analogRead(A0), 0, 1023, 0, 4);
  delay(250);
  perro(dato);
  
}
void activar() {

    MsTimer2::set(1000, conteo);
    MsTimer2::start();
}
void desactivar() {
  MsTimer2::stop();
  Serial.println("dasactivado");
}
void conteo() {
  j++;  
  if (j == 9 && var == 10) {
    wdt_enable(WDTO_1S);
    j=0;
  } if (j == 19 && var == 20) {
    wdt_enable(WDTO_1S);
    j=0;
  } if (j == 29 && var == 30) {
    wdt_enable(WDTO_1S);
    j=0;
  } if (j == 39 && var == 40) {
    wdt_enable(WDTO_1S);
    j=0;
  }
  Serial.println(j);
  delay(200);
}

void perro(int dato) {
  switch (dato) {
    case 0:
      break;
    case 1:
      var = 10;
      activar();
      break;
    case 2:
      var = 20;
      activar();
      break;
    case 3:
      var = 30;
      activar();
      break;
    case 4:
      var = 40;
      activar();
      break;
  }
}
