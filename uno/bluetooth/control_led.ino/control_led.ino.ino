#include <SoftwareSerial.h>
#define rxPin 2
#define txPin 3

SoftwareSerial bt = SoftwareSerial(rxPin, txPin);

void setup() {
  pinMode(rxPin, INPUT);  
  pinMode(txPin, OUTPUT);

  bt.begin(9600);
  Serial.begin(9600);
}

void loop() {
  bt.println("I am Ironman");
  delay(3000);
}
