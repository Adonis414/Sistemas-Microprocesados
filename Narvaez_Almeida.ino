#define ARM_MATH_CM3
#include <arm_math.h>
#define tam_inputSignal 640
#define tam_impulse 29
#define tam_sig2 500

extern float32_t points_ecg_[tam_inputSignal];
extern float32_t Impulse_response[tam_impulse];
extern float32_t Senal[tam_sig2];
float32_t signal_out[tam_inputSignal + tam_impulse];
float32_t OutputSignal1 [tam_inputSignal];
float32_t OutputSignal2 [tam_sig2];

float32_t desvE;
float32_t var;

float32_t desvE2;
float32_t var2;

float32_t REX1[tam_inputSignal];
float32_t IDX1[tam_inputSignal];

float32_t REX2[tam_sig2];
float32_t IDX2[tam_sig2];

void setup() {
  Serial.begin(9600);
}

void loop() {

//convolucion

  //  arm_conv_f32(&points_ecg_[0], tam_inputSignal, &Impulse_response[0], tam_impulse, &signal_out[0]);
  //  plot_sig(signal_out, tam_inputSignal + tam_impulse);
  //desviacion();

//suma y resta de la primera señal
  //suma(&points_ecg_[0], &OutputSignal1[0], tam_inputSignal);
  //resta(&points_ecg_[0], &OutputSignal1[0], tam_inputSignal);
  //plot_sig3();

//suma y resta de la segunda señal
  //suma(&Senal[0], &OutputSignal2[0], tam_sig2);
  //resta(&Senal[0], &OutputSignal2[0], tam_sig2);
  //plot_sig2();

//transformada de la primera señal
//  cal_tdf(&points_ecg_[0], &REX1[0], &IDX1[0], tam_inputSignal);
//  get_tdf1();
//  plot_signal4();

//transformada de la segunda señal
  cal_tdf(&Senal[0], &REX2[0], &IDX2[0], tam_sig2);
  get_tdf2();
  plot_signal5();

}
void plot_sig2() {
  uint32_t i;
  for (i = 0; i < tam_sig2; i++) {
    //Serial.println(Senal[i]);
    Serial.println(OutputSignal2[i]);
    delay(10);
  }
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
  arm_var_f32(&points_ecg_[0], tam_inputSignal, &var);
  Serial.println(var);
  //desviacion estandar
  desvE = sqrt(var);
  Serial.println(desvE);
  delay(1000);

  //Desviacion estandar de la segunda señal de 500 muestras
  Serial.println(" ");
  arm_var_f32(&Senal[0], tam_inputSignal, &var2);
  Serial.println(var2);
  //desviacion estandar
  desvE2 = sqrt(var2);
  Serial.println(desvE2);
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
void get_tdf2(void) {
  uint32_t i;
  for (i = 0; i < tam_sig2; i++) {
    OutputSignal2[i] = sqrt(pow(REX2[i], 2) + pow(IDX2[i], 2));
  }
}
//Impresion de la transformada de la primera señal
void plot_signal4() {
  uint32_t i;
  for (i = 0; i < tam_inputSignal; i++) {
    Serial.println(OutputSignal1[i]);

  }
}

//Impresion de la transformada de la segunda señal
void plot_signal5() {
  uint32_t i;
  for (i = 0; i < tam_sig2; i++) {
    Serial.println(OutputSignal2[i]);
  }
}
