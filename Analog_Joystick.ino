//www.elegoo.com
//2016.12.09

// Arduino pin numbers
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output
const int numLeds = 10;
int ledPins[2][4] = {
  {11, 10, 8, 5},
  {12, 9, 7, 6}
};
int row = 0;
int col = 0;
int NUM_ROWS = 1;
int NUM_COLS = 3;

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
  Serial.print(row);
  Serial.print("\n\n");
  Serial.print(col);
  Serial.print("\n\n");

  if (analogRead(X_pin) < 450) { // right
    digitalWrite(ledPins[row][col], LOW);
    col = min(col + 1, NUM_COLS);
    digitalWrite(ledPins[row][col], HIGH);    
  } else if (analogRead(X_pin) > 550) { //left
    digitalWrite(ledPins[row][col], LOW);
    if (col != 0) {
      col = col - 1;
    }
    digitalWrite(ledPins[row][col], HIGH);
  }
  
  if (analogRead(Y_pin) < 450) { // up
    digitalWrite(ledPins[row][col], LOW);
    if (row != 0) {
      row = row - 1;
    }
    digitalWrite(ledPins[row][col], HIGH);    
  } else if (analogRead(Y_pin) > 550) { //down
    digitalWrite(ledPins[row][col], LOW);
    if (row != 1) {
      row = row + 1;
    }
    digitalWrite(ledPins[row][col], HIGH);
  }
  
  if (digitalRead(SW_pin) == 0) {
    Serial.print("hi");
    for (int i = 0; i < numLeds; i++) {
       digitalWrite(ledPins[i], HIGH);
    }
  }

  delay(100);
}
