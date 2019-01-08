#include <LiquidCrystal.h>
#include <MsTimer2.h>


int cont=0;
int minutos=0;
int horas=0;
LiquidCrystal lcd (13,12,11,10,9,8);
void setup() {
  Serial.begin(9600);
  MsTimer2::set(1000,rutina);
  MsTimer2::start();
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

void rutina(){
  cont++;
 
  if(cont>59){
    minutos++;
    cont=0;
    if(cont==0){
      lcd.setCursor(9,0);
  lcd.print(" ");
    }
    if(minutos>59){
      horas++;
      minutos=0;
      cont=0;
    }
    if(horas>=24){
      horas=0;
      minutos=0;
      cont=0;
    }
  }

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
