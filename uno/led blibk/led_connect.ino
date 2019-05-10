int led_R = 10;
int led_G = 9;
int led_Y = 8;

void setup()
{
  Serial.begin(9600);

  pinMode(led_R, OUTPUT);
  pinMode(led_G, OUTPUT);
  pinMode(led_Y, OUTPUT);
}

void loop()
{
  // Red show
  Serial.println("Red display");
  digitalWrite(led_R, 1);
  digitalWrite(led_G, 0);
  digitalWrite(led_Y, 0);
  delay(1000);

  // Green show
  Serial.println("Green display");
  digitalWrite(led_R, 0);
  digitalWrite(led_G, 1);
  digitalWrite(led_Y, 0);
  delay(1000);

  // Yellow show
  Serial.println("Yellow display");
  digitalWrite(led_R, 0);
  digitalWrite(led_G, 0);
  digitalWrite(led_Y, 1);
  delay(1000);
}