/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Adonis Narváez
   Fecha: 08-01-2019

   Temas:
   1.- Realizar un reloj mediante el uso de timers
*/
#include <LiquidCrystal.h>//libreria para el lcd
#include <MsTimer2.h>//libreria del timer 2


int cont=0; //variable para los segundos
int minutos=0;  //variable para los minutos 
int horas=0;  //variable para las horas
LiquidCrystal lcd (13,12,11,10,9,8);  //pines para conectar el lcd
void setup() {
  Serial.begin(9600); //inicializar la comunicacion serial
  MsTimer2::set(1000,reloj); //Configurar el timer2
  MsTimer2::start();  //inicializar el timer
  //configuracion inicial del lcd
  lcd.begin(16,2);
  lcd.setCursor(4,0);
  lcd.print(':');
  lcd.setCursor(7,0);
  lcd.print(':');
  lcd.setCursor(8,0);
  lcd.print(cont);
  lcd.setCursor(5,0);
  lcd.print("00");
  lcd.setCursor(2,0);
  lcd.print("00");
}

void loop() {
  // put your main code here, to run repeatedly:
  

}
//rutina del timer
void reloj(){
  cont++; //contador para los segundos
 
  if(cont>59){
    minutos++;  //Contador para los minutos
    cont=0;     //resseteo de los segundos
    if(cont==0){
      lcd.setCursor(9,0); //impresion en el lcd c
  lcd.print(" ");
    }
    if(minutos>59){
      horas++;    //contador para las horas
      minutos=0;  //reseteo de los minutos
      cont=0;     //reseteo de los segundos
    }
    if(horas>=24){  //Finalizacion del horero
      horas=0;  //reseteo de las horas
      minutos=0;  //reseteo de los minutos
      cont=0; //reseteo de los segundos
    }
  }
    //impresion correcta en el lcd
  if(cont<=9){
    lcd.setCursor(9,0);
    lcd.print(cont);
    lcd.setCursor(8,0);
    lcd.print('0');
  }else{
    lcd.setCursor(8,0);
    lcd.print(cont);
  }  
  if(minutos<=9){
    lcd.setCursor(6,0);
    lcd.print(minutos);
    lcd.setCursor(5,0);
    lcd.print('0');
  }else{
    lcd.setCursor(5,0);
    lcd.print(minutos);
  }

  if(horas<=9){
    lcd.setCursor(3,0);
    lcd.print(horas);
    lcd.setCursor(2,0);
    lcd.print('0');
  }else{
    lcd.setCursor(2,0);
    lcd.print(horas);
  }
  
}
