
int RedLed = 23;
int BlueLed = 6;
int GreenLed = 5;
long tempo;
void setup() {
  Serial.begin(9600);   
  tempo = 1000;   
  pinMode(RedLed, OUTPUT);  
  pinMode(BlueLed, OUTPUT); 
  pinMode(GreenLed, OUTPUT);    
}

void loop() {
  if(Serial.available() > 0){
    tempo = Serial.parseInt();    
  }
  
  Serial.print("Allumée\n");
  analogWrite(BlueLed, 0);
  analogWrite(RedLed, 160);
  analogWrite(GreenLed, 200);
  delay(tempo);
  Serial.print("Eteinte\n");
  analogWrite(BlueLed, 0);
  analogWrite(RedLed, 0);
  analogWrite(GreenLed, 0);
  delay(tempo);
}
