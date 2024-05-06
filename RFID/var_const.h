int led0 = 10, led1 = 11, led2 = 12, led3 = 13, led4 = 14; //abre, cierra, pare, sensor 1 y 2
int boton = 8;          //abra, cierra, pare
int FCA;    // Final de Carrera Abierto, una vez que llega a x punto manda una señal al puerto de arduino, HIGH
int espera = 22; //tiempo de cerrado y apertura 
int FCC;    // Final de Carrera Cerrado
int estado_boton;
int ultimo_boton = HIGH;
bool salida;         //LOW = porton cerrado
unsigned long tiempo_actual;            
