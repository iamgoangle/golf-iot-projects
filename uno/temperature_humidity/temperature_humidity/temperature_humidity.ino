#include <dht11.h>

dht11 DHT11;
int sensorPin = 4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int chk = DHT11.read(sensorPin);

  Serial.print("Current humidity = ");
  Serial.print(DHT11.humidity);
  Serial.print("%  ");

  Serial.print("Temperature = ");
  Serial.print(DHT11.temperature); 
  Serial.println("C");

  delay(2000);
}
