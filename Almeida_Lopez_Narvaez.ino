#define ARM_MATH_CM3
#include <arm_math.h>
#define tam_inputSignal 535
#define tam_impulse 29

extern float32_t signal1[tam_inputSignal];
extern float32_t Impulse_response[tam_impulse];
float32_t signal_out[tam_inputSignal + tam_impulse];
float32_t OutputSignal1 [tam_inputSignal];

float32_t desvE;
float32_t var;

float32_t REX1[tam_inputSignal];
float32_t IDX1[tam_inputSignal];


void setup() {
  Serial.begin(9600);
}

void loop() {

  desviacion();

  //convolucion

  //arm_conv_f32(&signal1[0], tam_inputSignal, &Impulse_response[0], tam_impulse, &signal_out[0]);
  //plot_sig(signal_out, tam_inputSignal + tam_impulse);

  //suma y resta de la primera señal

  //suma(&signal1[0], &OutputSignal1[0], tam_inputSignal);
  //resta(&signal1[0], &OutputSignal1[0], tam_inputSignal);
  //plot_sig3();

  //transformada de la primera señal

  //cal_tdf(&signal1[0], &REX1[0], &IDX1[0], tam_inputSignal);
  //get_tdf1();
  //plot_signal4();
}

void plot_sig3() {
  uint32_t i;
  for (i = 0; i < tam_inputSignal; i++) {

    Serial.println(OutputSignal1[i]);
    delay(10);
  }
}
void plot_sig(float32_t *sig_entrada, uint32_t tam_sig) {
  uint32_t i;
  for (i = 0; i < tam_sig; i++) {
    Serial.println(sig_entrada[i] * 100);
    delay(10);
  }
}

void desviacion() {

  //Desviacion de la primera señal de 640 muestras
  //varianza
  arm_var_f32(&signal1[0], tam_inputSignal, &var);
  Serial.println(var);
  //desviacion estandar
  desvE = sqrt(var);
  Serial.println(desvE);
  delay(1000);
}

//suma de las señales

void suma(float32_t *input, float32_t *output, uint32_t tam) {
  uint32_t i;
  for (i = 0; i < tam; i++) {
    output[i] = input[i] + output[i - 1];
  }
}
//resta de las señales
void resta(float32_t *input, float32_t *output, uint32_t tam) {
  uint32_t i;
  for (i = 0; i < tam; i++) {
    output[i] = input[i] - input[i - 1];
  }
}

//calculo de la trasformada discreta de fourier
void cal_tdf(float32_t *input_sig, float32_t *sig_rex, float32_t *sig_idx, uint32_t tam) {

  uint32_t i, j, k;
  for (j = 0; j < tam; j++) {
    sig_rex[j] = 0;
    sig_idx[j] = 0;
  }

  for (k = 0; k < tam; k++) {
    for (i = 0; i < tam; i++) {
      sig_rex[k] = sig_rex[k] + input_sig[i] * cos(2 * PI * k * i / tam);
      sig_idx[k] = sig_idx[k] - input_sig[i] * sin(2 * PI * k * i / tam);
    }
  }
}

void get_tdf1(void) {
  uint32_t i;
  for (i = 0; i < tam_inputSignal; i++) {
    OutputSignal1[i] = sqrt(pow(REX1[i], 2) + pow(IDX1[i], 2));
  }
}

//Impresion de la transformada de la primera señal
void plot_signal4() {
  uint32_t i;
  for (i = 0; i < tam_inputSignal; i++) {
    Serial.println(OutputSignal1[i]);

  }
}
