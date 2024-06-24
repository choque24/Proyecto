
#include <RCSwitch.h>

//Control rf
const uint32_t CODIGO = 16242856;
long dato;
bool estado = false;
bool codigoValido = false;


// Constantes pines: botones, sensores y actuadores
const uint8_t BOTON = 9;      //Accion
const uint8_t BOTON2 = 12;    //Configuracion
const uint8_t SensorFCA = 6;  //Final de Carrera Abierto
const uint8_t SensorFCC = 7;  //Final de Carrera Cerrado
const uint8_t led0 = 10;      //direccion
const uint8_t led1 = 11;      //Activacion

//Variables estado: porton, botones, sensores y tiempo
uint8_t estado_porton = LOW;
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
    if (estado_porton == Frenado && !estado_FCA && condicion) {
      anterior_tiempo2 = millis();
      condicion = LOW;
      Serial.println("321");
    }
    if (estado_porton == Frenado && !estado_FCA && estado_FCC) {
      if (millis() - anterior_tiempo2 >= espera_temporizada) {
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
      if (!estado_FCA) estado_porton = Frenado;  //Si el porton se esta ABRIENDO y llego al FCA FRENAR el porton
      else estado_porton = Apertura;             //Abrir el porton hasta nuevo aviso
      break;

    case Cerraje:
      if (!estado_FCC) estado_porton = Frenado;  //Si el porton se esta CERRANDO y llego al FCC FRENAR el porton
      else estado_porton = Cerraje;              //Cerrar el porton hasta nuevo aviso
      break;

    case Frenado:
      if (!estado_FCC && estado_FCA && direccion == LOW) estado_porton = Apertura;       //Si el porton esta QUIETO y llego al FCC y se presiono el boton ABRIR el porton
      else if (estado_FCC && !estado_FCA && direccion == HIGH) estado_porton = Cerraje;  //Si el porton esta QUIETO y llego al FCA y se presiono el boton CERRAR el porton
      else if (estado_FCA && estado_FCC && direccion == LOW && condicion2) estado_porton = Apertura;
      else if (estado_FCA && estado_FCC && direccion == HIGH && condicion2) estado_porton = Cerraje;
      else estado_porton = Frenado;  //Frenar Porton hasta nuevo aviso
      break;

    default:
      parar_porton();
      break;
  }
}
