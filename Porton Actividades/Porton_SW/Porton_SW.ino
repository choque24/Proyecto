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
if (salida) Serial.print("something");
  switch (estado) {
    case BOTON:
    BOTON;
      break;
    case MOTOR_APAGADO:
      break;
    case ACT_MOTOR_ABIERTO:
      break;
    case ACT_MOTOR_CERRADO:
      break;
    default:
      break;
  }
}
