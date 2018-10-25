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
int pines[6] = {7, 8, 9, 10, 11, 12};//Creamos un vector con los pines a usar
int i;//inicializamos una variable i que cambiara en el codigo
void setup() {
  // put your setup code here, to run once:
  for (i = 0; i < 6; i++) {
    pinMode(pines[i], OUTPUT);//se ponen los pines como salidas
  }
  i = 0;
randomSeed(2);//nos sirve para inicializar el random en 2 
}

void loop() {
  
  //Programa 1: Juego de luces impares
  for (i = 0; i < 6; i = i + 2) {
    digitalWrite(pines[i], HIGH);//al incrementar de dos en dos solo se encenderan los leds imparesde una manera secuencial
    delay(100);
  }
  delay(100);
  for (i = 4; i >= 0; i = i - 2) {
    digitalWrite(pines[i], LOW);//asi mismo se debe decrementar para apagar los leds encendidios anteriormente
    delay(100);
  }
  i = 0;
  delay(300);//retardo utilizado para separar un juego del otro

  //Programa 2: Juego de las luces pares

  //estas lineas de codigo permiten encender y apagar el led uno por uno
  for (i = 1; i < 6; i = i + 2) {
    digitalWrite(pines[i], HIGH);//nos permite encender el led
    delay(100);//retardo entre el encendido y el apagado del led
    digitalWrite(pines[i],LOW);//nos permite apagar el led
    delay(100);
  }
  delay(300);
    i = 0;

  //Programa 3: Juego de luces aleatorios

  while(i>=0 && i<6){   //con el ciclo while poonemos los limites del ciclo
    int ran =random(1,7);// declaramos una varible de tipo int donde guardaremos nuestro numero random 
    digitalWrite(pines[ran],HIGH);//le asignamos al vector el numero random que se nos genero y encendemos el led
    delay(100);
    digitalWrite(pines[ran],LOW);//le asignamos al vector el numero random que se genero y apagamos el led
    delay(100);
    i++;//incremento para el ciclo while 
  }
  i=0;//reseteo de la variable
  delay(300);//retardo entre juegos

}
