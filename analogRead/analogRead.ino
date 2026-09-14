const int AnaloguePin=4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(AnaloguePin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int input=analogRead(AnaloguePin);
  Serial.println(input);
  delay(100);
}
