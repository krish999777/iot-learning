#include <WiFi.h> 
void setup() { 
  Serial.begin(115200);
  Serial.print("Connecting");
  WiFi.begin("JAKS-2.4GHz", "alpashah");
  while (WiFi.status() != WL_CONNECTED){
    delay(500); Serial.print(".");
  }
  Serial.println();
  Serial.println("Connected!");
  Serial.print("IP = ");
  Serial.println(WiFi.localIP()); 
} 
void loop() {

}