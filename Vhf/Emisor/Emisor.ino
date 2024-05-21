#include "var_const.h"
void setup() {
  Serial.begin(9600);
  rf_driver.init();  // inicializa objeto con valores por defecto
  for (int i = 0; i < 4; i++) {
    pinMode(botonPin[i], INPUT_PULLUP);  // configura los pines de los botones como entrada con resistencia pull-up
    pinMode(salidaPin[i], OUTPUT);       // configura los pines de las salidas como salida
  }
}
void loop() {
  if (digitalRead(botonPin[0]) == LOW) {
    const char *msg = "0";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    Serial.println(msg);
  } else if (digitalRead(botonPin[1]) == LOW) {
    const char *msg = "1";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    Serial.println(msg);
  } else if (digitalRead(botonPin[2]) == LOW) {
    const char *msg = "2";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    Serial.println(msg);
  } else if (digitalRead(botonPin[3]) == LOW) {
    const char *msg = "3";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    Serial.println(msg);
  }
  delay(50);
}
