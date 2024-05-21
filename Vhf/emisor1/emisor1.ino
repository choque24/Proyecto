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
  for (int i = 0; i < 4; i++) {
    int lecturaBoton = digitalRead(botonPin[i]);   // lee el estado del botón
    if (lecturaBoton != estadoBotonAnterior[i]) {  // si el estado del botón ha cambiado
      delay(50);
      //lecturaBoton = digitalRead(botonPin);
      if (lecturaBoton == LOW) {  // si el botón está presionado
        const char *msg = i;
        Serial.print("boton numero: ");
        Serial.println(i);                            // carga numero 1 en mensaje a enviar
        //Serial.print("valor enviado: ");
        //Serial.println(*msg);                            // carga numero 1 en mensaje a enviar
        rf_driver.send((uint8_t *)msg, strlen(msg));  // envia el mensaje
        rf_driver.waitPacketSent();                   // espera al envio correcto del mensaje
        estadoSalida[i] = !estadoSalida[i];
        digitalWrite(salidaPin[i], estadoSalida[i]);  // invierte el estado de la salida correspondiente
        Serial.print("estado boton: ");
        Serial.println(estadoSalida[i]);
        Serial.println("");
      }
      estadoBotonAnterior[i] = lecturaBoton;  // actualiza el estado anterior del botón
    }
  }
}