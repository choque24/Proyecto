#include "WString.h"
#include "Arduino.h"
const int led0 = 10, led1 = 11, led2 = 12, led3 = 13, led9 = 9; //abre, cierra, pare, sensor 1 y 2
const int boton = 8;          //abra, cierra, pare
//const int espera = 22; //tiempo de cerrado y apertura Porton 
const int SensorFCA = 2;    // Final de Carrera Abierto, una vez que llega a x punto manda una señal al puerto de arduino, HIGH
const int SensorFCC = 3;    // Final de Carrera Cerrado
bool estado_sensor = HIGH;
bool ultimo_sensor = HIGH;
bool estado_sensor2 = HIGH;
bool ultimo_sensor2 = HIGH;
bool estado_boton = HIGH;
bool ultimo_boton = HIGH;
bool salida;         //LOW = porton cerrado
unsigned long tiempo_actual;
unsigned long anterior_tiempo;
int boton_cerrado;
int boton_abierto;
enum estados{
  abriendo = 1,
  cerrando,
  detenido
};
int  opciones[] = {
  boton_cerrado = 1,
  boton_abierto = 2
 };
void apertura(){
  digitalWrite(led1, HIGH);
}
void cerradura(){ // 
  digitalWrite(led2, HIGH);
} 
void frenado(){ // FRENA
  digitalWrite(led3, HIGH);
}
