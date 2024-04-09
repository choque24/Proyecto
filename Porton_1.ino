#include "var_const.h"
void setup() {
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
//mientras se ejecuta la funcion cierra, abre, pregujntar si toca el boton, en caso de presionar detener y hacer lo contrario
//Si se presiona el boton cuando no esta en algun FC se frena, y gira para el otro lado
void loop() {
  estado_boton = digitalRead(boton);
  estado_sensor = digitalRead(SensorFCA);
  estado_sensor2 = digitalRead(SensorFCC);
  tiempo_actual = millis();

  if (boton == HIGH) {
    int i = 1;
    switch (opciones[i]) {
      case abriendo:  //abrir reja
        Serial.print("abriendo reja");
        break;
      case cerrando:
        Serial.print("hola");  //cerrar reja
        break;
      case detenido:
        Serial.print("poton automatico");  //iniciar temporizado
        break;
      default:
        Serial.print("");  // nada
        break;
    }
  }
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
    }
    ultimo_boton = estado_boton;
  }
  if (!estado_sensor || !estado_sensor2) {  //Pregunta si la reja ya se abrio/cerro
    Serial.println("porton Detenido");
    digitalWrite(led1, HIGH);  //funcion que detiene al porton
  } else {
    digitalWrite(led1, LOW);
  }
}
