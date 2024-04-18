#include "var_const.h"
#include "funciones.h"

void setup() {
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(SensorFCA, INPUT_PULLUP);
  pinMode(SensorFCC, INPUT_PULLUP);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  parar_porton();
}

void loop() {
  estado_boton = digitalRead(BOTON);
  estado_FCA = digitalRead(SensorFCA);
  estado_FCC = digitalRead(SensorFCC);
  tiempo_actual = millis();
  
  if (estado_boton != anterior_estado_boton) {
    delay(50);
    if (estado_boton == LOW) {
      boton_presionado++;
      if (boton_presionado > 2) {
        boton_presionado = 1;
      }
    }
    anterior_estado_boton = estado_boton;
  }

  verificacion_estado_porton();

  if (tiempo_actual - anterior_tiempo >= espera) {
    anterior_tiempo = tiempo_actual;
    switch (estado_porton) {
      case Apertura:  // Abre el porton
        Serial.println("Abriendo");
        digitalWrite(led0, HIGH);
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        break;

      case Cerraje:  // Cierra el porton
        Serial.println("Cerrando");
        digitalWrite(led0, LOW);
        digitalWrite(led1, HIGH);
        digitalWrite(led2, LOW);
        break;

      case Frenado:  // Frena el porton
        Serial.println("Frenado");
        digitalWrite(led0, LOW);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        break;

      default:
        Serial.println("cosas raras");
        break;
    }
  }
}