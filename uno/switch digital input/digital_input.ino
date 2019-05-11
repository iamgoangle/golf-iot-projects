// input from digital input 8
int sw = 8;

void setup()
{
  Serial.begin(9600); // watch serial monitor
  pinMode(sw, INPUT_PULLUP);
}

void loop()
{
  int val = digitalRead(sw);
  Serial.println(val);
  delay(600);
}