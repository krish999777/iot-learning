#include <HTTPClient.h>
#include <WiFi.h>

HTTPClient http;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin("JAKS-2.4GHz", "alpashah");
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(String("IP=") + WiFi.localIP());
  http.begin("http://192.168.29.125:8000/input");
  int responseCode = http.POST("");

    if (responseCode > 0) {
        Serial.println(responseCode);
        Serial.println(http.getString());
    }
    http.end();
}

void loop() {
  // put your main code here, to run repeatedly:
}
