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

void setup() {
  Serial.begin(9600);
}

void loop() {

  //  arm_conv_f32(&points_ecg_[0], tam_inputSignal, &Impulse_response[0], tam_impulse, &signal_out[0]);
  //  plot_sig(signal_out, tam_inputSignal + tam_impulse);
  //desviacion();

//  suma(&points_ecg_[0], &OutputSignal1[0], tam_inputSignal);
//  //resta(&InputSignal_1kHz_15kHz[0], &OutputSignal[0], tam_sig);
//  plot_sig2();

  suma(&Senal[0], &OutputSignal2[0], tam_sig2);
  //resta(&InputSignal_1kHz_15kHz[0], &OutputSignal[0], tam_sig);
  plot_sig2();
}
void plot_sig2() {
  uint32_t i;
  for (i = 0; i < tam_sig2; i++) {
    Serial.println(Senal[i]);
    //Serial.println(OutputSignal2[i]);
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

  void suma(float32_t *input, float32_t *output, uint32_t tam) {
    uint32_t i;
    for (i = 0; i < tam; i++) {
      output[i] = input[i] + output[i - 1];
    }
  }

  void resta(float32_t *input, float32_t *output, uint32_t tam) {
    uint32_t i;
    for (i = 0; i < tam; i++) {
      output[i] = input[i] - input[i - 1];
    }
  }
