/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Adonis Narváez
   Fecha: 10-01-2019

   Temas:
   1.- Realizar un reloj con alarma mediante el uso de timers
*/
#include <LiquidCrystal.h>//libreria para el lcd
#include <MsTimer2.h>//libreria del timer 2


int cont = 0; //variable para los segundos
int minutos = 45; //variable para los minutos
int horas = 4; //variable para las horas

String minutero;  //variable para la cx serial
String horero;    //variable para la cx

int minuto;     //variable para la conversion de string a int
int hora;       //variable para la conversion de String a int

boolean a = true; //bandera
boolean b= false; //bandera


LiquidCrystal lcd (13, 12, 11, 10, 9, 8); //pines para conectar el lcd
void setup() {
  Serial.begin(9600); //inicializar la comunicacion serial
  pinMode(7, OUTPUT); //salida para la alarma
  attachInterrupt(0, on, LOW);  //interrupcion 1
  attachInterrupt(1, off, LOW); //interrupcion 2
  MsTimer2::set(100, reloj); //Configurar el timer2
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
  //llamada al metodo de la alarma
  if (a == false) {
    alarma();
    a = true;
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
    }
    if (minutos > 59) {
      horas++;    //contador para las horas
      minutos = 0; //reseteo de los minutos
      cont = 0;   //reseteo de los segundos
    }
    if (horas >= 24) { //Finalizacion del horero
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
  }
  if (minutos <= 9) {
    lcd.setCursor(6, 1);
    lcd.print(minutos);
    lcd.setCursor(5, 1);
    lcd.print('0');
  } else {
    lcd.setCursor(5, 1);
    lcd.print(minutos);
  }

  if (horas <= 9) {
    lcd.setCursor(3, 1);
    lcd.print(horas);
    lcd.setCursor(2, 1);
    lcd.print('0');
  } else {
    lcd.setCursor(2, 1);
    lcd.print(horas);
  }
  //comparar tiempo de la alarma con la del reloj
  if(b==false){
if (hora < 24 && minuto < 60) {//limtes del horero y del minutero
    if (horas == hora && minutos == minuto) {
      digitalWrite(7, HIGH);  //salida en alto
    } else
    {
      digitalWrite(7, LOW);   //salida en bajo
    }
  } else {
    Serial.print("Hora ingresada incorrecta");  //mensaje de advertencia
  }
  }


}
//metodo de la alarma
void alarma() {
  if (Serial.available() > 0) {//ver si hay algo en la comunicacion serial
    b=false;
    Serial.print("Ingrese la hora: ");
    horero = Serial.readString();//lectura del string
    hora = String(horero).toInt();  //conversion de string a int
    delay(100);
    Serial.print("Ingrese los minutos: ");
    minutero = Serial.readString();//lectura del string
    minuto = String(minutero).toInt();//conversion de string a int
    delay(100);    
    Serial.println("ALARMA DEFINIDA.!!");//mensaje de confirmacion

    
  }
}

//metodo de encendido de la alarma
void on() {
  a = false;
  Serial.println("Ingrese la alarma: ");
  
}
//metodo de apagado de la alarma
void off() {
  digitalWrite(7,LOW);//salida en bajo
  b=true;
  Serial.println("Alarma Apagada");
  
}
