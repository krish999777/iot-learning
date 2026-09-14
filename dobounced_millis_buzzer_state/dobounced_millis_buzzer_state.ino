const int INPUTPIN=4;
const int BUZZERPIN=2;
int stableInput=HIGH;
int prevInput=HIGH;
int buzzerMode=LOW;
const long interval = 50;
unsigned long prevMillis=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(INPUTPIN,INPUT_PULLUP);
  pinMode(BUZZERPIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int input=digitalRead(INPUTPIN);
  unsigned long currentMillis=millis();
  if(prevInput!=input){
    prevMillis=currentMillis;
    prevInput=input;
  }else if(currentMillis-prevMillis>=interval&&!(stableInput==input)){
    stableInput=input;
    if(stableInput==LOW){
      buzzerMode=buzzerMode?LOW:HIGH;
    }
  }
  Serial.print("stableInput=");
  Serial.print(stableInput);
  Serial.print("Buzzer=");
  Serial.println(buzzerMode);
  
  digitalWrite(BUZZERPIN,buzzerMode);
}
