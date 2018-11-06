/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Adonis Narváez
   Fecha: 06-11-2018

   Temas:
   1.- realizar un sistema que permita contar de forma automática 
   (sin pulsador, el sistema inicia y empieza a contar sin necesidad
   de una actividad del usuario). Del 1 al 200 mediante la multiplexación de displays.
*/

int A=5;
int B=4;
int C=3;
int D=2;
int i=0;

int cent=10;
int dec=9;
int uni=8;

int centenas;
int decenas;
int unidades;
void setup() {
  // put your setup code here, to run once:
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 
 pinMode(9,OUTPUT);
 pinMode(8,OUTPUT);
 pinMode(10,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
 
    if(i<200){
      i++;
      
      unidades=i %10;
      decenas =((i%100)/10);
      centenas=i/100;
    }
    else{
      i=0;
      unidades=0;
      decenas=0;
      centenas=0;
    }
  
   digitalWrite(uni,HIGH);
   digitalWrite(dec,LOW);
   digitalWrite(cent,LOW);
   display1(unidades);
   delay(100);
   
   digitalWrite(uni,LOW);
   digitalWrite(dec,HIGH);
   digitalWrite(cent,LOW);
   display1(decenas);
   delay(100);
   
   digitalWrite(uni,LOW);
   digitalWrite(dec,LOW);
   digitalWrite(cent,HIGH);
   display1(centenas);
   delay(100);
}


void display1(int j){
 switch(j){
  
  //0
case 0:digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//1
case 1: digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;;
//2
case 2: digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//3
case 3: digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,LOW);
digitalWrite(D,LOW);
break;
//4
case 4:digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//5
case 5:digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
delay(200);
//6
case 6:digitalWrite(A,LOW);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//7
case 7:digitalWrite(A,HIGH);
digitalWrite(B,HIGH);
digitalWrite(C,HIGH);
digitalWrite(D,LOW);
break;
//8
case 8:digitalWrite(A,LOW);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
//9
case 9:digitalWrite(A,HIGH);
digitalWrite(B,LOW);
digitalWrite(C,LOW);
digitalWrite(D,HIGH);
break;
 }
}
