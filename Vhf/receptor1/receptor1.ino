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
  uint8_t buf[1];                      // espacio para mensaje recibido de 1 caracter
  uint8_t buflen = sizeof(buf);        // longitud de buffer
  if (rf_driver.recv(buf, &buflen)) {  // si se recibieron datos correctos
    Serial.println((char*)buf);
    Serial.println((char)buf);
    switch ((char)buf[0]) {
      case '0':
        digitalWrite(salidaPin[0], !digitalRead(salidaPin[0]));
        Serial.println("boton 0");
        break;
      case '1':
        digitalWrite(salidaPin[1], !digitalRead(salidaPin[1]));
        Serial.println("boton 1");
        break;
      case '2':
        digitalWrite(salidaPin[2], !digitalRead(salidaPin[2]));
        Serial.println("boton 2");
        break;
      case '3':
        digitalWrite(salidaPin[3], !digitalRead(salidaPin[3]));
        Serial.println("boton 3");
        break;
      default:
        Serial.println("nada");
        break;
    }
    /*
    for (int i = 0; i < 4; i++) {
      if ((char)buf[0] == i) {                        // si el caracter es el numero 1estadoSalida[i] = !estadoSalida[i];
        digitalWrite(salidaPin[i], estadoSalida[i]);  // invierte el estado de la salida correspondiente
        Serial.println(estadoSalida[i]);
      }
      delay(50);
    }*/
  }
}
