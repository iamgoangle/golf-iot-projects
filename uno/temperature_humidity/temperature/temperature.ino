#include <dht11.h>
#define DHT11PIN 4

dht11 DHT11;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  int dht11Input = DHT11.read(DHT11PIN);

  Serial.print("Temperature (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(2000);
}
