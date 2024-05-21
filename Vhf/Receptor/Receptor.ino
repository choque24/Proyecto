#include "var_const.h"
void setup() {
  Serial.begin(9600);
  rf_driver.init();  // inicializa objeto con valores por defecto rec(11),trans(12)
  for (int i = 0; i < 4; i++) {
    pinMode(botonPin[i], INPUT_PULLUP);  // configura los pines de los botones como entrada con resistencia pull-up
    pinMode(salidaPin[i], OUTPUT);       // configura los pines de las salidas como salida
  }
}

void loop() {
  uint8_t buf[1];
  uint8_t buflen = sizeof(buf);
  if (rf_driver.recv(buf, &buflen)) {
    Serial.println(buf[0]);
    if ((char)buf[0] == '48') {
      digitalWrite(botonPin[0], !digitalRead(botonPin[0]));
    } else if ((char)buf[0] == '49') {
      digitalWrite(botonPin[1], !digitalRead(botonPin[1]));
    } else if ((char)buf[0] == '50') {
      digitalWrite(botonPin[2], !digitalRead(botonPin[2]));
    } else if ((char)buf[0] == '51') {
      digitalWrite(botonPin[3], !digitalRead(botonPin[3]));
    } else {
      Serial.write("nada");
    }
  }
}
