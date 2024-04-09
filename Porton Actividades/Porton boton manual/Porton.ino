#include "var_const.h"
void setup() {
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
  pinMode(SensorFCA, INPUT);
  pinMode(SensorFCC, INPUT);
  Serial.begin(9600);
}

void loop() {
  //tiempo_actual = millis();
  estado_sensor = digitalRead(SensorFCA);
  estado_sensor2 = digitalRead(SensorFCA);
  while (!estado_sensor || !estado_sensor2) {  //Pregunta si la reja abierta cerrada
    estado_boton = digitalRead(boton);
    estado_sensor = digitalRead(SensorFCA);
    if (estado_boton != ultimo_boton) {  //Va a cerrar o abrir
      delay(50);
      if (estado_boton == LOW) {
        digitalWrite(led0, !digitalRead(led0));  //cierra y abre por completo
        digitalWrite(led1, LOW);
        Serial.println("porton in movement");
        Serial.print("Estado Boton:  ");
        Serial.println(estado_boton);
        Serial.print("Ultimo Boton:  ");
        Serial.println(ultimo_boton);
      }
      ultimo_boton = estado_boton;
    } else {  //el porton se detiene
    digitalWrite(led1, HIGH);
    }
  }
  //funcion que detiene el portón
}
