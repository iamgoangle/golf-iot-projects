int vr_pin = A0;

void setup()
{
  pinMode(vr_pin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  int vr = analogRead(vr_pin);
  Serial.println(vr);
  delay(600);
}
