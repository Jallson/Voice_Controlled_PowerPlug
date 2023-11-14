#include <Wire.h>

int pin = 9;
int x;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);

  Wire.begin(9);
  Wire.onReceive(receiveEvent);

}

void loop() {
  // put your main code here, to run repeatedly:

}

void receiveEvent(int howMany) {
  x = Wire.read();
  Serial.println(x);
  if (x == 1) {
    pin = 5;
  }
  else if (x == 2) {
    pin = 6;
  }
  else if (x == 3) {
    pin = 7;
  }
  else if (x == 4) {
    pin = 8;
  }
  else if (x == 5) {
    digitalWrite(pin, LOW);
    pin = 9;
  }
  else if (x == 6) {
    digitalWrite(pin, HIGH);
    pin = 9;
  }
}