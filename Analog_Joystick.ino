//www.elegoo.com
//2016.12.09

// Arduino pin numbers
 // aconst int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0;nalog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int numLeds = 10;
int ledPins[numLeds] = {12, 11, 10, 9, 8, 7, 6, 5, 3, 22};
int index = 0;


void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);
  
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  Serial.print("Switch:  ");
  Serial.print(digitalRead(SW_pin));
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(analogRead(X_pin));
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.println(analogRead(Y_pin));
  Serial.print("\n\n");
  
  if (analogRead(X_pin) < 450) { // right
    digitalWrite(ledPins[index], LOW);
    index = min(numLeds - 1, index + 1);
    digitalWrite(ledPins[index], HIGH);    
  } else if (analogRead(X_pin) > 550) { //left
    digitalWrite(ledPins[index], LOW);
    index = max(0, index - 1);
    digitalWrite(ledPins[index], HIGH);
  }

  if (digitalRead(SW_pin) == 0) {
    Serial.print("hi");
    for (int i = 0; i < numLeds; i++) {
       digitalWrite(ledPins[i], HIGH);
    }
  }
}
