#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// WiFi
const char *ssid = "xxx";
const char *password = "xxx";

// LINE
const String lineHost = "notify-api.line.me";
const String notifyApi = "/api/notify";
const String token = "xxx";
const int httpsPort = 443;

// Use web browser to view and copy
// SHA1 fingerprint of the certificate
// https://en.wikipedia.org/wiki/Public_key_fingerprint
// https://www.facebook.com/longhackz/posts/1692042657717181/
const char fingerprint[] PROGMEM = "BF 16 AE 79 D2 AB 71 44 BE D8 E7 55 A2 C7 0B 39 68 DB B5 D2";

const int httpTimeout = 5000;

void connectNetwork()
{
  WiFi.mode(WIFI_OFF); // Prevents reconnection issue (taking too long to connect)
  delay(1000);
  WiFi.mode(WIFI_STA);        // Only Station No AP, This line hides the viewing of ESP as wifi hotspot
  WiFi.begin(ssid, password); // WiFi connection

  while (WiFi.status() != WL_CONNECTED)
  { //Wait for the WiFI connection completion
    delay(500);
    Serial.println("Waiting for connection");
  }

  Serial.println();
  Serial.println("WiFi connected");
}

void lineNotify(String msg, bool debug)
{
  if (WiFi.status() == WL_CONNECTED)
  {
    WiFiClientSecure httpsClient;
    Serial.print("Connecting to ... ");
    Serial.println(lineHost);

    // certificate pinning
    Serial.printf("Using fingerprint ... '%s'\n", fingerprint);
    httpsClient.setFingerprint(fingerprint);
    httpsClient.setTimeout(httpTimeout);
    delay(1000);

    if (!httpsClient.connect(lineHost, httpsPort))
    {
      Serial.println("Connection failed");
      return;
    }

    Serial.print("[HTTPS] begin...");
    String lineNotifyMessage = "message=" + msg;
    int lineMessageContentLen = String(lineNotifyMessage).length();

    String req = "";
    req += "POST /api/notify HTTP/1.1\r\n";
    req += "Host: " + lineHost + "\r\n";
    req += "Authorization: Bearer " + token + "\r\n";
    req += "User-Agent: line-iot\r\n";
    req += "Connection: close\r\n";
    req += "Content-Type: application/x-www-form-urlencoded\r\n";
    req += "Content-Length: " + String(lineMessageContentLen) + "\r\n";
    req += "\r\n";
    req += lineNotifyMessage;

    if (debug)
    {
      Serial.print("\nRequest payload: ");
      Serial.println(req);
    }

    // Send http request
    httpsClient.print(req);
    delay(100);

    // Checking timeout
//    unsigned long timeout = millis();
//    while (httpsClient.available() == 0)
//    {
//      if (millis() - timeout > httpTimeout)
//      {
//        Serial.println("Connection timeout !");
//        httpsClient.stop();
//        return;
//      }
//    }

    while (httpsClient.connected())
    {
      String line = httpsClient.readStringUntil('\n');
      if (line == "\r")
      {
        Serial.println("Push LINE Notify successfull!");
        break;
      }
    }

    String line = httpsClient.readStringUntil('\n');
    Serial.println("reply was:");
    Serial.println("==========");
    Serial.println(line);
    Serial.println("==========");
    Serial.println("closing connection");
  }
}

void setup()
{
  Serial.begin(115200);

  connectNetwork();
}

void loop()
{
  lineNotify("test iot", true);
  delay(5000);
}
