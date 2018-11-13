#include<stdlib.h>
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    String cedula = Serial.readString();
    validarCedula(cedula);
  }
}

void validarCedula(String cedula2) {

  char digito1 = cedula2.charAt(0);
  char digito2 = cedula2.charAt(1);
  char digito3 = cedula2.charAt(2);
  char digito10 = cedula2.charAt(9);
  int validador[] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
  int valor;
  int total = 0;

  int n1 = digito1 - 48;
  int n2 = digito2 - 48;
  int n3 = digito3 - 48;
  int n10 = digito10 - 48;
  int total2 = 0;



  if (cedula2.length() == 10) {
    if (n1 >= 1 || n1 <= 2 && n2 >= 0 || n2 <= 4) {
      if (n3 < 6 && n3 >= 0) {
        for (int i = 0; i < 9; i++) {
          valor = validador[i] * (((cedula2.charAt(i) - 48)));
          if (valor >= 10) {
            valor = valor - 9;
          }
          total = total + valor;
          total2 = 10 - (total % 10);
          if (total2 == 10) {
            total2 = 0;
          }

        }

        if (total2 == n10) {
          Serial.print(": ");
          Serial.println("Cedula correcta");
          delay(200);

        } else {
          Serial.print(": ");
          Serial.println("Cedula Incorrecta no cumple las condiciones");
          delay(200);

        }

      } else {
        Serial.print(": ");
        Serial.println("Cedula Incorrecta tercer digito incorrecto");
        delay(200);
      }

    } else {
      Serial.print(": ");
      Serial.println("Cedula Incorrecta primeros digitos incorrectos");
      delay(200);
    }
  } else if (cedula2.length() < 10) {
    Serial.print(": ");
    Serial.println("Cedula Incorrecta la cedula tiene menos de 10 digitos");
    delay(200);

  } else if (cedula2.length() > 10) {
    Serial.print(": ");
    Serial.println("Cedula Incorrecta la cedula tiene mas de 10 digitos");
    delay(200);

  }

}
