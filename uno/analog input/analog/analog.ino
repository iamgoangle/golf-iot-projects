int vr_pin = A0;
int led_pin = 11;

void setup()
{
  pinMode(vr_pin, INPUT);
  pinMode(led_pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int vr = analogRead(vr_pin);

  // map from low to range of value
  // 0 - 255
  int vrRage = map(vr, 0, 1023, 0, 255);

  analogWrite(led_pin, vr);
  
  Serial.println(vrRage);
//  delay(500);
}
