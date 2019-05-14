int ldr = A0;

void setup()
{
  Serial.begin(9600);
  pinMode(ldr, INPUT);
}

void loop()
{
  int ldrVal = analogRead(ldr);
  Serial.println(ldrVal);

  delay(500);
}
