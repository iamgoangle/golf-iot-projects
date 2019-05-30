/**
 * @project Controle LED via WiFi with Blynk 
 * @author  Teerapong Singthong <st.teerapong@gmail.com>
 * @desc    medium.com/iamgoangle
 */
 
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk Auth Token
char auth[] = "xxx";

// WiFi
char ssid[] = "xxx";
char pass[] = "xxx";

void setup()
{
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();
}
