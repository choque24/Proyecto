const int gatePin = 9; // the pin that the gate is connected to
const int buttonPin = 2; // the pin that the button is connected to

int gateState = 0; // the current state of the gate (0 = closed, 1 = opening, 2 = open, 3 = closing)
int lastButtonState = LOW; // the last state of the button

unsigned long lastDebounceTime = 0; // the last time the button state changed
unsigned long debounceDelay = 50; // the debounce delay in milliseconds

void setup() {
  pinMode(gatePin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }

  if (millis() - lastDebounceTime > debounceDelay) {
    if (buttonState == HIGH) {
      if (gateState == 0 || gateState == 2) {
        gateState = 1;
      } else if (gateState == 1 || gateState == 3) {
        gateState = 2;
      }
    }
  }

  lastButtonState = buttonState;

  switch (gateState) {
    case 0:
      digitalWrite(gatePin, LOW);
      break;
    case 1:
      digitalWrite(gatePin, HIGH);
      break;
    case 2:
      digitalWrite(gatePin, HIGH);
      break;
    case 3:
      digitalWrite(gatePin, LOW);
      break;
  }
}