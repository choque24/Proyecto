// Constantes para los pines de los botones y sensores
const int BOTON = 8;
const int SensorFCA = 2;
const int SensorFCC = 3;
const int led0 = 10;
const int led1 = 11;
const int led2 = 12;

int estado_porton = 0;
bool estado_boton = HIGH;
bool anterior_estado_boton = HIGH;
bool estado_FCA = HIGH;
bool estado_FCC = HIGH;
int boton_presionado = 0;

unsigned long tiempo_actual;
unsigned long anterior_tiempo;
const int espera = 1000;

enum {  // Constantes para los estados del porton
  Frenado = 0,
  Apertura,
  Cerraje
};

