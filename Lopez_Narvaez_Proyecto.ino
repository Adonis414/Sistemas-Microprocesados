#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {5, 4, 3, 2};
byte colPins[COLS] = {9, 8, 7, 6};
char pwsd1 [5] = {'*', '*', 'A', 'B', 'C'};
char pwsd2 [5] = {'#', '#', 'A', 'B', 'C'};
char pwsd3 [5] = {'*', '*', 'B', 'C', 'D'};
char pwsd4 [5] = {'#', '#', 'B', 'C', 'D'};
char master [5] = {'*', '*', 'A', '#', '#'};

int A = 13;
int B = 12;
int C = 11;
int D = 10;
int vector[5];
int vector2[5];
int i = 0;
int j = 0;
int k = 0;
int cont = 0;
String contrasena;
boolean a = false;
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(0, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(1, OUTPUT);
}

void loop() {
  char customKey = customKeypad.getKey();
  if (customKey) {

    switch (i) {

      case 0:
        vector[i] = customKey;
        i++;
        Serial.print(customKey);
        break;
      case 1:
        vector[i] = customKey;
        i++;
        Serial.print(customKey);
        break;
      case 2:
        vector[i] = customKey;
        i++;
        Serial.print(customKey);
        break;

      case 3:
        vector[i] = customKey;
        i++;
        Serial.print(customKey);
        break;
      case 4:
        vector[i] = customKey;
        Serial.print(customKey);
        Serial.print(": ");
        if (cont != 3) {

          if (vector[0] == pwsd1[0] && vector[1] == pwsd1[1] && vector[2] == pwsd1[2] && vector[3] == pwsd1[3] && vector[4] == pwsd1[4]) {

            Serial.println("CONTRASENA CORRECTA");
            Serial.println("Empleado Ingresado correctamente");
            cont = 0;

          }
          else if (vector[0] == pwsd2[0] && vector[1] == pwsd2[1] && vector[2] == pwsd2[2] && vector[3] == pwsd2[3] && vector[4] == pwsd2[4]) {

            Serial.println("CONTRASENA CORRECTA");
            Serial.println("Empleado Ingresado correctamente");
            cont = 0;

          }
          else if (vector[0] == pwsd3[0] && vector[1] == pwsd3[1] && vector[2] == pwsd3[2] && vector[3] == pwsd3[3] && vector[4] == pwsd3[4]) {

            Serial.println("CONTRASENA CORRECTA");
            Serial.println("Empleado Ingresado correctamente");
            cont = 0;

          }
          else if (vector[0] == pwsd4[0] && vector[1] == pwsd4[1] && vector[2] == pwsd4[2] && vector[3] == pwsd4[3] && vector[4] == pwsd4[4]) {

            Serial.println("CONTRASENA CORRECTA");
            Serial.println("Empleado Ingresado correctamente");
            cont = 0;

          }
          else {
            Serial.println("CONTRASENA INCORRECTA!!! Ingrese Nuevamente");
            cont++;
            if (cont == 3) {
              Serial.print("Ingrese clave Master: ");

            }
          }
          i = 0;
          break;

        } else if (cont == 3) {
          if (vector[0] == master[0] && vector[1] == master[1] && vector[2] == master[2] && vector[3] == master[3] && vector[4] == master[4]) {
            Serial.println("CONTRASENA MASTER CORRECTA");

          }
          cont = 0;
          i = 0;
        }
    }

  }


  if (digitalRead(0) == LOW) {
    delay(500);
    k++;
    
    if (k > 9) {
      k = 0;
    }
    
  }
  display1(k);
}

void display1(int j) {
  switch (j) {

    //0
    case 0: digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    //1
    case 1: digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;;
    //2
    case 2: digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    //3
    case 3: digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, LOW);
      digitalWrite(D, LOW);
      break;
    //4
    case 4: digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    //5
    case 5: digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      delay(200);
    //6
    case 6: digitalWrite(A, LOW);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    //7
    case 7: digitalWrite(A, HIGH);
      digitalWrite(B, HIGH);
      digitalWrite(C, HIGH);
      digitalWrite(D, LOW);
      break;
    //8
    case 8: digitalWrite(A, LOW);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
    //9
    case 9: digitalWrite(A, HIGH);
      digitalWrite(B, LOW);
      digitalWrite(C, LOW);
      digitalWrite(D, HIGH);
      break;
  }
}
