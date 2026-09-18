#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

void handleRoot(){
  Serial.println("Root");
  server.send(200, "text/plain", "Hello from ESP32");
}

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting");
  WiFi.begin("JAKS-2.4GHz", "alpashah");
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Connected");
  Serial.print("Ip=");
  Serial.println(WiFi.localIP());
  server.on("/",HTTP_GET,handleRoot);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
