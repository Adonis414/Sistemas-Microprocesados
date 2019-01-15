#include <EEPROM.h>

/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Adonis Narváez
   Fecha: 10-01-2019

   Temas:
   1.-Realice un sistema que guarde en una posición de la memoria
   EEPROM solo cuando su valor exceda a la anterior lectura.
*/

String var; //variable para la comunicacion serial
int num;    // convertir variable de string a int
void setup() {
  Serial.begin(9600); //Inicializar la CX serial
  EEPROM.write(0, 0); //Reseatear la posicion cero con un valor de cero
}

void loop() {

  if (Serial.available() >= 0) {  //comprobar si hay algo en la CX serial
    Serial.print("Ingrese el valor a guardar entre 0 y 255: "); //mensaje de informacion
    delay(500); 
    var = Serial.readString();  //Tomar valor del monitor serie
    num = var.toInt();          //convertir string a int
    if (EEPROM.read(0) < num) { //condicion para guardar informacion
      EEPROM.update(0, num);    //actualizar la EEPROM en la posicion 0
      Serial.print("El valor guardado en la EEPROM es: ");  //mensaje de confirmacion
      Serial.println(EEPROM.read(0)); //Impresion por serial del valor en la EEPROM
      delay(100);
    } else {
      Serial.println("No puede ingresar letras o el valor es igual o menor al guardado. "); //mensaje de advertencia
      delay(100);
    }
  }
}
