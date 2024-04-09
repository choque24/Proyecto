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
  if (estado_boton != ultimo_boton) {  //Va a cerrar o abrir
    delay(50);
    if (estado_boton == LOW) {
      if (digitalRead(led1) == LOW) {
        digitalWrite(led0, !digitalRead(led0));  //cierra y abre por completo
        delay(1000);
        Serial.println("Se detuvo y cambio de lado");
      } else {
        delay(1000);
        digitalWrite(led0, !digitalRead(led0));  //cierra y abre por completo
        Serial.println("Empieza a abrir/cerrar Reja");
      }
      if (digitalRead(led0) == HIGH) {
        Serial.println("Abre");
      } else {
        Serial.println("Cierra");
      }
    }
    ultimo_boton = estado_boton;
  }
  estado_sensor = digitalRead(SensorFCA);
  estado_sensor2 = digitalRead(SensorFCC);

  if (!estado_sensor || !estado_sensor2) {  //Pregunta si la reja ya se abrio/cerro
    Serial.println("porton Detenido");      // escendido = derecha | apagado = izquierda
    digitalWrite(led1, HIGH);               //funcion que detiene al porton
  } else {
    digitalWrite(led1, LOW);
  }
}
