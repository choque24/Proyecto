const int buttonPin = 2; // Button pin
const int sensorPin1 = 3; // Sensor pin 1
const int sensorPin2 = 4; // Sensor pin 2
const int motorPin = 5; // Motor pin

int buttonState = 0; // Button state
int sensorState1 = 0; // Sensor state 1
int sensorState2 = 0; // Sensor state 2
int counter = 0; // Counter
int sensorStateAnt = LOW; // Previous sensor state

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  sensorState1 = digitalRead(sensorPin1);
  sensorState2 = digitalRead(sensorPin2);

  if (!sensorState1 && sensorStateAnt) { // Debounce button and detect button press
    counter++;
    if (counter > 2) counter = 2; // Limit counter to 2
  }
  sensorStateAnt = sensorState1;

  switch (counter) {
    case 0: // Stop
      digitalWrite(motorPin, LOW);
      break;
    case 1: // Forward
      if (sensorState1 == HIGH) {
        digitalWrite(motorPin, LOW);
      } else {
        digitalWrite(motorPin, HIGH);
      }
      break;
    case 2: // Backward
      if (sensorState2 == HIGH) {
        digitalWrite(motorPin, LOW);
      } else {
        digitalWrite(motorPin, HIGH);
      }
      break;
  }
}