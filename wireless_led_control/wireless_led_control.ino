#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);
int state=LOW;
const int ledPin=4;

void handleRoot(){
  Serial.println("Root");
  server.send(200, "text/plain", "Hello from ESP32");
}
void handleLed(){
  if(server.hasArg("state")==1){
    state=server.arg("state")=="on"?HIGH:LOW;
  }else{
    state=state?LOW:HIGH;
  }
  server.send(200,"text/plain",state?"ON":"OFF");
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin,OUTPUT);
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
  server.on("/led",HTTP_GET,handleLed);
  server.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
  digitalWrite(ledPin,state);
}
