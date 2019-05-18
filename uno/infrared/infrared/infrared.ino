int pinD0 = 8;
int analogA0 = A0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // digital signal
  int sensorRead = digitalRead(pinD0);
  Serial.print(sensorRead);
  Serial.print("\t");
  
  if (sensorRead == 0) {
    Serial.println("ʘ‿ʘ Detect something ~~~~ ");
  } else {
    Serial.println("(ᗒᗣᗕ)՞ Not found movement ~~~~ ");
  }

  // analog signal
//  int sensorRead = analogRead(analogA0);
//  Serial.println(sensorRead);
  
  delay(300);
}
