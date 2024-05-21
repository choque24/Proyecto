#include <RH_ASK.h>  // incluye libreria RadioHead.h
#include <SPI.h>     // incluye libreria SPI necesaria por RadioHead.h

const int botonPin[] = { 2, 3, 4, 5 };                   // pines de los botones
const int salidaPin[] = { 6, 7, 8, 9 };                  // pines de las salidas
int estadoBotonAnterior[] = { HIGH, HIGH, HIGH, HIGH };  // almacena el estado anterior de cada botón
int estadoSalida[] = { LOW, LOW, LOW, LOW };

RH_ASK rf_driver;  // crea objeto para modulacion por ASK