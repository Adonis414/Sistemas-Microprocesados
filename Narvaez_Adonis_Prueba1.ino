#include <EEPROM.h>
#include <avr/wdt.h>
/*
          Universidad Tecnica del Norte
                 Fica-Ciercom

     Nombre: Adonis Narváez
     Fecha: 22-01-2019

     Actividad: Se necesita emular el funcionamiento de un control de auto ChevyStar.
     Para ello, se tienen las siguientes características.
      • Se cuenta con 4 botones, uno máster y 3 para la contraseña.
      • La contraseña es de 5 dígitos que debe ser la combinación de los 3 botones.
      • El sistema al presionar una vez (solo botón máster) y sin contraseña envía por
      comunicación serial el mensaje de activado o desactivado.
      • Si es digitada la contraseña es correcta (se presiona la combinación de los 3 botones y
      luego el máster), envía por mensaje serial que se puede encender el carro. Caso contrario,
      se tendrá hasta 2 intentos más para acertar a la contraseña. Si no es el caso, el control
      se reinicia y genera otra contraseña de forma aleatoria de la combinación de los pulsadores.
      La nueva contraseña se envía por comunicación serial.
*/

int cont = 0;
int i = 0;
int correc = 0;
int k = 0;
int n;

int digito1;
int digito2;
int digito3;
int digito4;
int digito5;
int pass[5];

int num1;
int num2;
int num3;
int num4;
int num5;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //iniciar la cx serial
  attachInterrupt(0, on, LOW);    //Interrupcion
  pinMode(3, INPUT);    //pin como entrada
  pinMode(4, INPUT);    //pin como entrada
  pinMode(5, INPUT);    //pin como entrada
  pinMode(13, INPUT);   //pin como entrada
  wdt_disable();        //desactivar el perro guardian
  Serial.println("Bienvenido");     //mensaje de bienvenida
}

void loop() {
    //limpiar la EEPROM
    if(digitalRead(13)==LOW){
      limpiar();
      wdt_enable(WDTO_15MS);
    }

    //Ingresar contrasena
  if (cont == 1) {
    if (digitalRead(3) == LOW) {
      delay(200);
      pass[i] = 1;
      i++;
      Serial.print(1);
    } else if (digitalRead(4) == LOW) {
      delay(200);
      pass[i] = 2;
      i++;
      Serial.print(2);
    } else if (digitalRead(5) == LOW) {
      delay(200);
      pass[i] = 3;
      i++;
      Serial.print(3);
    }
  }
}

//metodo de activacion del sistema
void on() {

  switch (cont) {
    case 0:
      Serial.println("Sistema Activado");
      Serial.print("Ingrese la contrasena: ");
      cont++;
      break;
    case 1:
      contrasena();   //llamado del metodo
      if (correc == 10) {
        Serial.println("Se puede encender el auto");
        cont++;
        i = 0;
      } else if (k < 3) {
        Serial.print("Ingrese nuevamente la contrasena: ");
        cont = 1;
      } else {
        Serial.println("Reiniciando el sistema");
        generar();
        Serial.print("Nueva contrasena: ");
        Serial.print(EEPROM.read(0));
        Serial.print(EEPROM.read(1));
        Serial.print(EEPROM.read(2));
        Serial.print(EEPROM.read(3));
        Serial.println(EEPROM.read(4));
        wdt_enable(WDTO_500MS);

      }
      break;
    case 2:
      Serial.println("Sistema OFF");
      cont = 0;
      break;
  }
}

//metodo para validar la contrasena
void contrasena() {
  digito1 = pass[0];
  digito2 = pass[1];
  digito3 = pass[2];
  digito4 = pass[3];
  digito5 = pass[4];

  num1 = EEPROM.read(0);
  num2 = EEPROM.read(1);
  num3 = EEPROM.read(2);
  num4 = EEPROM.read(3);
  num5 = EEPROM.read(4);


  if (digito1 == num1 && digito2 == num2 && digito3 == num3 && digito4 == num4 && digito5 == num5 ) {
    Serial.println(" ");
    Serial.println("Contrasena correcta");
    correc = 10;
    k = 0;
  } else {
    Serial.println(" ");
    Serial.println("Contrasena incorrecta");
    correc = 11;
    i = 0;
    k++;
  }
}
//generador de contrasena nueva
void generar () {
  for (i = 0; i < 5; i++) {
    n = random(1, 4);
    pass[i] = n;
  }

  
  EEPROM.write(0, pass[0]); delay(10);
  EEPROM.write(1, pass[1]); delay(10);
  EEPROM.write(2, pass[2]); delay(10);
  EEPROM.write(3, pass[3]); delay(10);
  EEPROM.write(4, pass[4]); delay(10);
}

//metodo para limpiar la EEPROM
void limpiar() {
  for (i = 0; i < 256; i++) {
    EEPROM.write(i, 0);
  } Serial.println("EEPROM limpia");

  EEPROM.write(0, 1);
  EEPROM.write(1, 1);
  EEPROM.write(2, 1);
  EEPROM.write(3, 1);
  EEPROM.write(4, 1);
}
