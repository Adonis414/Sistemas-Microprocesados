/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Adonis Narváez
   Fecha: 25-10-2018

   Temas:
   1.- Realizar un juego de lueces que se prendan secuencialmente los leds impartes (1,3,5).
   2.- Realizar un programa que se enciendan uno por uno los leds pares (0,2,4).
   3.- Realizar un juego que se enciendan y apaguen los leds de forma aleatoria.
*/
int pines[6] = {7, 8, 9, 10, 11, 12};
int i;
void setup() {
  // put your setup code here, to run once:
  for (i = 0; i < 6; i++) {
    pinMode(pines[i], OUTPUT);
  }
  i = 0;
randomSeed(2);
}

void loop() {
  
  //Programa 1: Juego de luces impares
  for (i = 0; i < 6; i = i + 2) {
    digitalWrite(pines[i], HIGH);
    delay(100);
  }
  delay(100);
  for (i = 4; i >= 0; i = i - 2) {
    digitalWrite(pines[i], LOW);
    delay(100);
  }
  i = 0;
  delay(300);

  //Programa 2: Juego de las luces pares

  for (i = 1; i < 6; i = i + 2) {
    digitalWrite(pines[i], HIGH);
    delay(100);
    digitalWrite(pines[i],LOW);
    delay(100);
  }
  delay(300);
    i = 0;

  //Programa 3: Juego de luces aleatorios

  
  for(i=0;i<6;i++)
  {
    int n=random(1,7);
    digitalWrite(pines[n], HIGH);
    delay(100);
    digitalWrite(pines[n],LOW);
    delay(100);
  }
  delay(500);
  i=0;

}
