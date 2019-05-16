int ldr = A0;
int led = 11;

void setup()
{
  Serial.begin(9600);
  
  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  int ldrVal = analogRead(ldr);

  Serial.println("LDR Sensor");
  Serial.println(ldrVal);

  if (ldrVal > 400) {
    digitalWrite(led, 255);
  } else {
    digitalWrite(led, 0);
  }

  delay(500);
}
