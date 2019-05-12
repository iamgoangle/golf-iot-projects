// input from digital input 8
int sw = 8;
int led = 9;
int ledOn = 1;
int ledOff = 0;

void setup()
{
  Serial.begin(9600); // watch serial monitor
  pinMode(sw, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}

void loop()
{
  int val = digitalRead(sw);

  if (val == 0)
  {
    Serial.println("Led is on");
    digitalWrite(led, ledOn);
  }
  else
  {
    Serial.println("Led is off");
    digitalWrite(led, ledOff);
  }

  delay(600);
}