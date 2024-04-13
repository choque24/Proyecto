#include "var_const.h"
void setup() {
  // put your setup code here, to run once:
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
  pinMode(SensorFCA, INPUT_PULLUP);
  pinMode(SensorFCC, INPUT_PULLUP);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  estado_boton = digitalRead(boton);
  estado_sensor = digitalRead(SensorFCA);
  estado_sensor2 = digitalRead(SensorFCC);
  tiempo_actual = millis();
  if (estado_boton != ultimo_boton) {  //Va a cerrar o abrir
    delay(50);
    if (estado_boton == LOW) {
      if (indice > 1) {
        indice = 0;
      }
      if (!estado_sensor) {
        FC = HIGH;
        Serial.println("Llego al FCC");
      } else if (!estado_sensor2) {
        FA = HIGH;
        Serial.println("Llego al FCA");
      }
      indice++;

      estado = indice;
    }
    ultimo_boton = estado_boton;
  }

  if (!estado_sensor || !estado_sensor2) {  //Pregunta si la reja ya se abrio/cerro
    estado = detenido;
  }
  if (tiempo_actual - anterior_tiempo >= espera) {
    anterior_tiempo = tiempo_actual;
    switch (estado) {
      case abriendo:  //abrir reja
        apertura();
        break;
      case cerrando:
        cerradura();
        break;
      case detenido:
        frenado();
        break;
      default:
        Serial.print("No pasa nada");  // nada
        break;
    }
  }
}