#include "var_const.h"
void setup() {
  mySwitch.enableReceive(0);  // Recepción por interrupción 0 => Eso es en el pin 2
  //pinMode(LED, OUTPUT);
  pinMode(BOTON, INPUT_PULLUP);
  pinMode(BOTON2, INPUT_PULLUP);
  pinMode(SensorFCA, INPUT_PULLUP);
  pinMode(SensorFCC, INPUT_PULLUP);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
  estado_porton = Frenado;
}
void loop() {  // el codigo automatico corre, si se presiona el boton manual, se pausa, si se vuelve a presionar se reanuda
  if (mySwitch.available()) {
    dato = mySwitch.getReceivedValue();
    mySwitch.resetAvailable();
  }
  estado_boton = digitalRead(BOTON);
  estado_boton2 = digitalRead(BOTON2);

  if (estado_boton2 != anterior_estado_boton2) {
    delay(100);
    if (estado_boton2 == LOW) modos = !modos;
    anterior_estado_boton2 = estado_boton2;
  }

  if (estado_boton != anterior_estado_boton || dato == CODIGO) {
    delay(100);
    if (estado_boton == LOW || dato == CODIGO) {
      mySwitch.disableReceive();
      codigoValido = true;
      dato = 0;
      anterior_tiempo3 = millis();
      var_FCA = HIGH;
      var_FCC = HIGH;
      if (estado_porton == Apertura || estado_porton == Cerraje) {
        estado_porton = Frenado;
        Serial.println("boton_medio");
        condicion2 = LOW;
      } else {
        Serial.println("boton_Accion");
        direccion = !direccion;
        condicion2 = HIGH;
      }
    }
    anterior_estado_boton = estado_boton;
  }

  if (millis() - anterior_tiempo3 > INTERVALO && codigoValido == true) {
    codigoValido = false;
    mySwitch.enableReceive(0);
  }

  estado_FCA = digitalRead(SensorFCA);
  estado_FCC = digitalRead(SensorFCC);

  if (estado_FCA != anterior_estado_FCA) {
    delay(100);
    if (!estado_FCA) {
      Serial.println("FCA");
      var_FCA = LOW;
      var_FCC = HIGH;
    }
    anterior_estado_FCA = estado_FCA;
  }

  if (estado_FCC != anterior_estado_FCC) {
    delay(100);
    if (!estado_FCC) {
      Serial.println("FCC");
      var_FCC = LOW;
      var_FCA = HIGH;
    }
    anterior_estado_FCC = estado_FCC;
  }

  verificacion_estado_porton();

  if (millis() - anterior_tiempo >= espera) {
    anterior_tiempo = millis();
    switch (estado_porton) {
      case Apertura:  // Abre el porton
        abrir_porton();
        mensajes("Abriendo");
        break;

      case Cerraje:  // Cierra el porton
        cerrar_porton();
        mensajes("Cerrando");
        break;

      case Frenado:  // Frena el porton
        parar_porton();
        mensajes("Frenado");
        break;

      default:
        Serial.println("cosas raras");
        break;
    }
    Serial.print("Modo: ");
    Serial.print(modos);
    Serial.print("    |||    direccion: ");
    Serial.print(direccion);
    Serial.print("    |||    activacion: ");
    Serial.println(activacion);
    Serial.println("");
  }
}