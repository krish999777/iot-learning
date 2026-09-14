const int LEDPIN=4;
const int INPUTPIN=34;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  ledcAttach(LEDPIN,5000,8);
  pinMode(INPUTPIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int input=analogRead(INPUTPIN);
  int brightness;
  if(input==0){
    brightness=0;
  }else{
    brightness=(int)((input/4095.0)*100);
  }
  if(brightness==0){
    ledcWrite(LEDPIN,0);
    return;
  }
  float cycles=(int)((brightness/100.0)*255);
  ledcWrite(LEDPIN,cycles);
}
