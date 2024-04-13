const int led0 = 10, led1 = 11, led2 = 12, led3 = 13, led9 = 9; //abre, cierra, pare, sensor 1 y 2
const int boton = 8;          //abra, cierra, pare
const int espera = 1000; //tiempo de cerrado y apertura Porton
const int SensorFCA = 2;    // Final de Carrera Abierto, una vez que llega a x punto manda una señal al puerto de arduino, HIGH
const int SensorFCC = 3;    // Final de Carrera Cerrado
bool estado_sensor = HIGH;
bool ultimo_sensor = HIGH;
bool estado_sensor2 = HIGH;
bool ultimo_sensor2 = HIGH;
bool estado_boton = HIGH;
bool ultimo_boton = HIGH;
bool FC = LOW;
bool FA = LOW;
unsigned long tiempo_actual;
unsigned long anterior_tiempo;
int indice = 0;

enum opciones {
  detenido = 0,
  abriendo,
  cerrando,
};
byte estado = opciones(indice);

void apertura() {
  digitalWrite(led0, HIGH);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  Serial.println("Apertura Activada");
}
void cerradura() {  //
  digitalWrite(led0, LOW);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  Serial.println("Cerradura Activada");
}
void frenado() {  // FRENA
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  Serial.println("Quieto");
}


