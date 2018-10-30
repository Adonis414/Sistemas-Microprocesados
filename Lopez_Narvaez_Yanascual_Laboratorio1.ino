/*      UNIVERSIDAD TÉCNICA DEL NORTE
 *              FICA-CIERCOM
 *       SISTEMAS MICROPROCESADOS    
 * 
 * Integrantes: López Sofía, Narváez Adonis, Yanascual Cintya.
 * Fecha: 30 de Octubre del 2018.
 * 
 * Ejercicios: 
 * 1.- Realizar 4 juegos de luces con activación mediante switchs.
 * 2.- Realizar un contador binario del 1 al 31.
 */
int salida[6] = {7, 8, 9, 10, 11, 12}; //Vector con los pines de salida
int entrada[5] = {2, 3, 4, 5, 6}; //Vector con los pines de entrada
int i = 0;
int contador = 0;
void setup() {
  // put your setup code here, to run once:
  for (i = 0; i < 6; i++) {
    pinMode(salida[i], OUTPUT);//Se ponen los pines como salidas
  }
  i = 0;

  for (i = 0; i < 5; i++) {
    pinMode(entrada[i], INPUT_PULLUP); //Se ponen los pines como entradas pull-up(Evitar poner pull-up externo) 
  }
  i = 0;
  randomSeed(2);  //Sirve para dar un inicio al numero randomico.
}

void loop() {

  // Lectura de las entradas guardadas en variables
  int a = digitalRead(2);
  int b = digitalRead(3);
  int c = digitalRead(4);
  int d = digitalRead(5);

//Ejercicio 1: Juegos de luces con activación del switch.

//Encender leds impares de manera secuencial.
  if (a == HIGH) { //Se toma la lectura del pin y se verifica si esta en alto(HIGH). 
    for (i = 7; i <= 12; i++) {
      digitalWrite(i, LOW);     //Sirve para apagar todos los leds en cada cambio de juego
    }
    for (i = 0; i < 6; i = i + 2) {
      digitalWrite(salida[i], HIGH);//al incrementar de dos en dos solo se encenderan los leds impares de una manera secuencial
      delay(500);
    }
    delay(500);
    for (i = 4; i >= 0; i = i - 2) {
      digitalWrite(salida[i], LOW);//asi mismo se debe decrementar para apagar los leds encendidios anteriormente
      delay(500);
    }
    contador = 0; //Inicializa la variable para el contador binario

//Encender leds pares uno por uno.

  } if (b == HIGH) {//Se toma la lectura del pin y se verifica si esta en alto(HIGH).
    for (i = 7; i <= 12; i++) {
      digitalWrite(i, LOW); //Sirve para apagar todos los leds en cada cambio de juego.
    }
    for (i = 1; i < 6; i = i + 2) {
      digitalWrite(salida[i], HIGH);//nos permite encender el led
      delay(500);//retardo entre el encendido y el apagado del led
      digitalWrite(salida[i], LOW); //nos permite apagar el led
      delay(500);
    }
    contador = 0; //Inicializa la variable para el contador binario.

  //Encender leds de manera aleatoria.
  
  } if (c == HIGH) {//Se toma la lectura del pin y se verifica si esta en alto(HIGH).

    for (i = 7; i <= 12; i++) {
      digitalWrite(i, LOW);     //Sirve para apagar todos los leds en cada cambio de juego.
    }
    for (i = 0; i < 6; i++) {
      int  r = random(0, 7); //Sirve para dar números aleatorios, se empieza desde uno y al número mayor que se utilizará en este caso para los leds que son 6 se suma 1
      digitalWrite(salida[r], HIGH); //Se pone en HIGH o alto (encendido) la posición i del vector
      delay(500);                 //tiempo de espera en ms
      digitalWrite(salida[r], LOW); //Se pone en LOW o bajo (apagado) la posición i del vector
      delay(500);
    }
    i = 0;
    contador = 0; //Inicializa la variable para el contador binario

//Encender leds en parejas de adentro hacia afuera y viceversa.
    
  } if (d == HIGH) {//Se toma la lectura del pin y se verifica si esta en alto(HIGH).

    //Este ciclo ayuda a encender los leds extremos hacia la parte interna
    for (; i < 3; i++) { 
      digitalWrite(salida[i], HIGH);
      digitalWrite(salida[5 - i], HIGH);
      delay(500);
    }
    i = 2;
    
    //Este ciclo ayuda a apagar los leds desde la parte interna hacia los extremos
    for (; i >= 0; i--) {
      digitalWrite(salida[i], LOW);
      digitalWrite(salida[5 - i], LOW);
      delay(500);
    }
    i = 0;
    contador = 0; //Inicializa la variable para el contador binario
  }

//Ejercicio 2: Contador binario del 0 al 31.

  else if (digitalRead(6) == LOW) {
    // Si se presiona el pulsador
    contador++; // Aumento el contador en 1
    while (digitalRead(6) == LOW) // Al presionar no hace nada mas

      if (digitalRead(6) > 31) { // Si el contador es mayor a 31,
        contador = 0; // se resetea el contador
      }

    int k = contador;
    for (int i = 7; i <= 11; i++) { //Ciclo para ver que leds se prenderan
      digitalWrite(i, k % 2);// contador mod 2...si el resultado es 1 se prende, si es 0 se apaga el led
      k = k / 2; // Se divide el cociente para 2 en cada ciclo para ir decrementando

    }
    delay(100);
  }


}
