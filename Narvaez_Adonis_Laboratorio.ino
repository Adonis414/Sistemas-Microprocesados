#include <MsTimer2.h>
#include <LiquidCrystal.h>
/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Adonis Narváez
   Fecha: 10-01-2019

   Temas:
   1.-Realice un reloj con un pulsador con las funciones de modificar la hora
   y crear la alarma. Otro pulsador para modificar el valor del minutero para
   actualizar la hora y la alarma y otro que permita actualizar el horero.
*/
int cont = 0; //variable para los segundos
int minutos = 1; //variable para los minutos
int horas = 12; //variable para las horas

String minutero;  //variable para la cx serial
String horero;    //variable para la cx

int minuto;     //variable para la conversion de string a int
int hora;       //variable para la conversion de String a int

boolean a = true; //bandera
boolean b = false; //bandera

long T0;
long T1;

int hora2;
int minuto2;
int num;

LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //pines para conectar el lcd
void setup() {
  Serial.begin(9600); //inicializar la comunicacion serial
  pinMode(7, OUTPUT); //salida para la alarma
  //attachInterrupt(0, confReloj, HIGH);  //interrupcion 1
  //attachInterrupt(1, off, HIGH); //interrupcion 2
  MsTimer2::set(1000, reloj); //Configurar el timer2
  MsTimer2::start();  //inicializar el timer
  //configuracion inicial del lcd
  lcd.begin(16, 2);
  lcd.setCursor(4, 1);
  lcd.print(':');
  lcd.setCursor(7, 1);
  lcd.print(':');
  lcd.setCursor(8, 1);
  lcd.print(cont);
  lcd.setCursor(5, 1);
  lcd.print("00");
  lcd.setCursor(2, 1);
  lcd.print("00");
}

void loop() {
  on();
  off();
  if (digitalRead(A2) == HIGH) {
    limpiar();
    lcd.setCursor(0, 0);
    lcd.print("Modifique hora");
    num = 0;
    confReloj();
    delay(5000);
    limpiar();
    lcd.setCursor(0, 0);
    lcd.print("Modifique min");
    num = 1;
    confReloj();
    delay(5000);
  }

}
//rutina del timer
void reloj() {
  cont++; //contador para los segundos
  if (cont > 59) {
    minutos++;  //Contador para los minutos
    cont = 0;   //resseteo de los segundos
    if (cont == 0) {
      lcd.setCursor(9, 1); //impresion en el lcd c
      lcd.print(" ");
    }if (minutos > 59) {
      horas++;    //contador para las horas
      minutos = 0; //reseteo de los minutos
      cont = 0;   //reseteo de los segundos
    }if (horas >= 24) { //Finalizacion del horero
      horas = 0; //reseteo de las horas
      minutos = 0; //reseteo de los minutos
      cont = 0; //reseteo de los segundos
    }
  }
  //impresion correcta en el lcd
  if (cont <= 9) {
    lcd.setCursor(9, 1);
    lcd.print(cont);
    lcd.setCursor(8, 1);
    lcd.print('0');
  } else {
    lcd.setCursor(8, 1);
    lcd.print(cont);
  } if (minutos <= 9) {
    lcd.setCursor(6, 1);
    lcd.print(minutos);
    lcd.setCursor(5, 1);
    lcd.print('0');
  } else {
    lcd.setCursor(5, 1);
    lcd.print(minutos);
  }if (horas <= 9) {
    lcd.setCursor(3, 1);
    lcd.print(horas);
    lcd.setCursor(2, 1);
    lcd.print('0');
  } else {
    lcd.setCursor(2, 1);
    lcd.print(horas);
  }
  //comparar tiempo de la alarma con la del reloj
  if (b == false) {
    if (hora < 24 && minuto < 60) {//limtes del horero y del minutero
      if (horas == hora && minutos == minuto) {
        digitalWrite(7, HIGH);  //salida en alto
      } else
      {
        digitalWrite(7, LOW);   //salida en bajo
      }
    }
  }
}
//metodo de la alarma
void alarma() {
  if (Serial.available() >= 0) {//ver si hay algo en la comunicacion serial
    b = false;
    limpiar();
    lcd.setCursor(0, 0);
    lcd.print("Ingrese hora:");
    delay(4000); 
    horero = Serial.readString();//lectura del string
    hora = String(horero).toInt();  //conversion de string a int
    lcd.setCursor(14, 0);
    lcd.print(hora);
    delay(4000);
    limpiar();
    lcd.setCursor(0, 0);
    lcd.print("Ing minutos:");
    delay(4000);
    minutero = Serial.readString();//lectura del string
    minuto = String(minutero).toInt();//conversion de string a int
    lcd.setCursor(14, 0);
    lcd.print(minuto);
    delay(4000);
    limpiar();
    lcd.setCursor(0, 0);
    lcd.print("ALARMA DEFINIDA");//mensaje de confirmacion
    delay(3000);
    limpiar();

  }
}

void confReloj() {
  switch (num) {
    case 0:
      if (Serial.available() >= 0) {
        limpiar();
        lcd.setCursor(0, 0);
        lcd.print("Ingrese hora:");
        delay(4000);
        horero = Serial.readString();//lectura del string
        hora2 = String(horero).toInt();  //conversion de string a int
        lcd.setCursor(14, 0);
        lcd.print(hora2);
        delay(4000);
        horas = hora2;
      }

      break;
    case 1:

      if (Serial.available() >= 0) {
        limpiar();
        lcd.setCursor(0, 0);
        lcd.print("Ing minutos:");
        delay(4000);
        minutero = Serial.readString();//lectura del string
        minuto2 = String(minutero).toInt();//conversion de string a int
        lcd.setCursor(14, 0);
        lcd.print(minuto2);
        delay(4000);
        minutos = minuto2;
      }
      break;
  }
}
//metodo de encendido de la alarma
void on() {
  delay(100);
  limpiar();
  if (digitalRead(A0) == HIGH) {
    a = false;
    limpiar();
    delay(10);
    lcd.setCursor(0, 0);
    lcd.print("Ingrese alarma");
    alarma();
    delay(3000);
    limpiar();
  }
}
//metodo de apagado de la alarma
void off() {
  delay(100);

  if (digitalRead(A1) == HIGH) {
    digitalWrite(7, LOW); //salida en bajo
    b = true;
    limpiar();
    lcd.setCursor(0, 0);
    lcd.print("Alarma Apagada");
    delay(2000);
    hora = 0;
    minuto = 0;
  }
}

void limpiar() {
  lcd.setCursor(0, 0);
  lcd.print(" "); lcd.setCursor(1, 0);
  lcd.print(" "); lcd.setCursor(2, 0);
  lcd.print(" "); lcd.setCursor(3, 0);
  lcd.print(" "); lcd.setCursor(4, 0);
  lcd.print(" "); lcd.setCursor(5, 0);
  lcd.print(" "); lcd.setCursor(6, 0);
  lcd.print(" "); lcd.setCursor(7, 0);
  lcd.print(" "); lcd.setCursor(8, 0);
  lcd.print(" "); lcd.setCursor(9, 0);
  lcd.print(" "); lcd.setCursor(10, 0);
  lcd.print(" "); lcd.setCursor(11, 0);
  lcd.print(" "); lcd.setCursor(12, 0);
  lcd.print(" "); lcd.setCursor(13, 0);
  lcd.print(" "); lcd.setCursor(14, 0);
  lcd.print(" "); lcd.setCursor(15, 0);
  lcd.print(" ");
}
