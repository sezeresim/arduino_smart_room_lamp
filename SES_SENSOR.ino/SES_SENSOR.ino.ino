const int DO_pin = 2;
const int AO_pin = 0;
int ses;
int led = 13; 


void setup() {
 pinMode(DO_pin, INPUT);
 pinMode(led, OUTPUT);
 Serial.begin(9600);
}
  
void loop() {

  //Sensor Control
  int data = digitalRead(DO_pin);
  Serial.println(data);
  //Sensor Control End
  int kontrol=0;
    if (ses > 520 && kontrol==0) {
      digitalWrite(led, HIGH);
      kontrol=1;
}

 if (ses > 520 && kontrol==1) {
  digitalWrite(led, LOW);
  kontrol=0;}
  
 ses = analogRead(AO_pin);
 
 Serial.print(digitalRead(DO_pin));
 Serial.print("-");
 Serial.println(analogRead(AO_pin)); 
}

