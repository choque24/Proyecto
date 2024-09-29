#include "Arduino.h"
#include <RCSwitch.h>

//Control rf
const uint32_t CODIGO = 16242856;
long dato;
bool estado = false;
bool codigoValido = false;

// Constantes pines: botones, sensores y actuadores
const uint8_t BOTON = 4;      //Acción
const uint8_t BOTON2 = 13;    //Configuración
const uint8_t SensorFCA = 5;  //Final de Carrera Abierto
const uint8_t SensorFCC = 3;  //Final de Carrera Cerrado
const uint8_t led0 = 11;      //Direccion
const uint8_t led1 = 12;      //Activacion

//Variables estado: porton, botones, sensores y tiempo
uint8_t estado_porton = LOW; //Frenado, Apertura, Cerraje
bool direccion = HIGH;  //"0" = Abriendo, "1" = Cerrando
bool activacion = LOW;  //"0" = Apagado, "1" = Encendido
bool modos = LOW;

bool estado_boton = HIGH;   //Manual
bool estado_boton2 = HIGH;  //Tempo
bool estado_boton3 = HIGH;  //MOD
bool anterior_estado_boton = HIGH;
bool anterior_estado_boton2 = HIGH;
bool anterior_estado_boton3 = HIGH;

bool estado_FCA = HIGH;
bool estado_FCC = HIGH;
bool var_FCA = HIGH;
bool var_FCC = HIGH;
bool anterior_estado_FCA = HIGH;
bool anterior_estado_FCC = HIGH;


bool condicion = HIGH;
bool condicion2 = LOW;

unsigned long anterior_tiempo = 0;
unsigned long anterior_tiempo2 = 0;
unsigned long anterior_tiempo3 = 0;
const uint16_t espera = 1000;
const uint16_t espera_temporizada = 10000;
const uint16_t INTERVALO = 1000;

//Creacion objetos
RCSwitch mySwitch = RCSwitch();

enum {  // Constantes para los estados del porton
  Frenado = 0,
  Apertura,
  Cerraje,
};

void abrir_porton() {  // Funcion para abrir el porton
  activacion = HIGH;
}
void cerrar_porton() {  // Funcion para cerrar el porton
  activacion = HIGH;
}
void parar_porton() {  // Funcion para parar el porton
  activacion = LOW;
}
void mensajes(String mensaje) {  //Prender leds, luego será reemplazada por en las funciones de arriba como las salidas
  digitalWrite(led0, direccion);
  digitalWrite(led1, activacion);
  Serial.print("Porton: ");
  Serial.println(mensaje);
}
// Funcion verificacion estados
void verificacion_estado_porton() {

  if (modos) {
    if (estado_porton == Frenado && !var_FCA && condicion) {
      anterior_tiempo2 = millis();
      condicion = LOW;
      Serial.println("321");
    }
    if (estado_porton == Frenado && !var_FCA) {
      if (millis() - anterior_tiempo2 >= espera_temporizada) {   //espera un tiempo determinado y CIERRA el porton
        anterior_tiempo2 = millis();
        estado_porton = Cerraje;
        direccion = HIGH;
        condicion = HIGH;
        Serial.println("123");
      }
    }
  }

  switch (estado_porton) {
    case Apertura:
      if (!var_FCA) estado_porton = Frenado;  //Si el porton se esta ABRIENDO y llego al FCA FRENAR el porton
      else estado_porton = Apertura;          //Abrir el porton hasta nuevo aviso
      break;

    case Cerraje:
      if (!var_FCC) estado_porton = Frenado;  //Si el porton se esta CERRANDO y llego al FCC FRENAR el porton
      else estado_porton = Cerraje;           //Cerrar el porton hasta nuevo aviso
      break;

    case Frenado:
      if (!var_FCC && var_FCA && !direccion) estado_porton = Apertura;                   //Si el porton esta QUIETO en FCC y se presionó el boton ABRIR el porton
      else if (var_FCC && !var_FCA && direccion) estado_porton = Cerraje;                //Si el porton esta QUIETO en FCA y se presiono el boton CERRAR el porton
      else if (var_FCA && var_FCC && !direccion && condicion2) estado_porton = Apertura; //Si el porton esta QUIETO en mitad de recorrido y se presionó el boton ABRIR el porton
      else if (var_FCA && var_FCC && direccion && condicion2) estado_porton = Cerraje;   //Si el porton esta QUIETO en mitad de recorrido y se presionó el boton CERRAR el porton
      else estado_porton = Frenado;  //Frenar Porton hasta nuevo aviso
      break;

    default:
      parar_porton();
      break;
  }
}