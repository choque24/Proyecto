#include <Arduino.h>

const int buttonPin = 8;
const int openSensorPin = 2;
const int closeSensorPin = 4;
const int motorPin = 5;
const int led0 = 10;
const int led1 = 11;
const int closingDelay = 5000; // 5 seconds

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(openSensorPin, INPUT_PULLUP);
  pinMode(closeSensorPin, INPUT_PULLUP);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
}

void loop() { //NO USAR DELAY
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//NO USAR DELAY /// USAR MILLIS()))()()()()()(())
//  // Check if /// USAR MILLIS()))()()()()()(()) the button is pressed
  Serial.println("esperando boton");
  digitalWrite(led1, HIGH);
  if (!digitalRead(buttonPin) == HIGH) {
    // Wait for the button to be released
    while (!digitalRead(buttonPin) == HIGH) {
      delay(10);
    }
    Serial.println("boton presionado");
    Serial.println("Empieza mecanismo Porton");
    Serial.println("Abriendo");


    // Start opening the gate
    digitalWrite(motorPin, HIGH);
    digitalWrite(led0, HIGH);
    digitalWrite(led1, LOW);

    // Wait for the open sensor to be triggered
  while (!digitalRead(openSensorPin) == LOW) {
      delay(10);
    }
    Serial.println("Llegó al final");
    Serial.println("Espera 5 segundos");

    // Stop the motor
    digitalWrite(motorPin, LOW);
    digitalWrite(led1, HIGH);

    // Wait for the closing delay
    delay(closingDelay);
    Serial.println("Empieza a cerrar porton");

    // Start closing the gate
    digitalWrite(motorPin, HIGH);
    digitalWrite(led0, HIGH);
    digitalWrite(led1, LOW);

    // Wait for the close sensor to be triggered
    while (!digitalRead(openSensorPin) == LOW) {
      delay(10);
    }
    Serial.println("Llegó al final");
    Serial.println("Se detiene por completo");

    // Stop the motor
    digitalWrite(motorPin, LOW);

  }
}