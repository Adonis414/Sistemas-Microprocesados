/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Adonis Narváez
   Fecha: 06-11-2018

   Temas:
   1.- Realizar un programa que medienta un pulsador se aumente el
   valor de un contador (1 al 40) y mediante otro pulsador se reste
   ese valor. El visualización del proceso se lo hace en displays.
*/
int A=5;
int B=4;
int C=3;
int D=2; 
int b1=6;
int b2=7;
int i=1;
int dec=9;
int uni=8;
int decenas;
int unidades;
void setup() {
  // put your setup code here, to run once:
 pinMode(2,OUTPUT);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(b1,INPUT_PULLUP);
 pinMode(b2,INPUT_PULLUP);
 pinMode(9,OUTPUT);
 pinMode(8,OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(b1)==LOW){
    delay(250);
    if(i<41){
      i++;
      decenas =i/10;
      unidades=i %10;
    }
    else{
      i=1;
      unidades=1;
      decenas=0;
    }
  }
  digitalWrite(uni,HIGH);
   digitalWrite(dec,LOW);
   display1(unidades);
   delay(100);
   digitalWrite(uni,LOW);
   digitalWrite(dec,HIGH);
   display1(decenas);
   delay(100);
   
  if(digitalRead(b2)==LOW){
    delay(250);
    if(i<41){
      i--;
      decenas =i/10;
      unidades=i %10;
    }
    else{
      i=1;
      unidades=1;
      decenas=0;
    }
   digitalWrite(uni,HIGH);
   digitalWrite(dec,LOW);
   display1(unidades);
   delay(100);
   digitalWrite(uni,LOW);
   digitalWrite(dec,HIGH);
   display1(decenas);
   delay(100);
}
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
