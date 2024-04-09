#include "Arduino.h"
const int led0 = 10, led1 = 11, led2 = 12, led3 = 13, led4 = 14; //abre, cierra, pare, sensor 1 y 2
const int boton = 8;          //abra, cierra, pare
const int espera = 22; //tiempo de cerrado y apertura Porton 
const int SensorFCA = 2;    // Final de Carrera Abierto, una vez que llega a x punto manda una señal al puerto de arduino, HIGH
const int SensorFCC = 3;    // Final de Carrera Cerrado
bool estado_sensor = LOW;
bool ultimo_sensor = LOW;
bool estado_sensor2 = LOW;
bool ultimo_sensor2 = LOW;
bool estado_boton = LOW;
bool ultimo_boton = HIGH;
bool salida;         //LOW = porton cerrado
unsigned long tiempo_actual;            
