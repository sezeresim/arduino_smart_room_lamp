const int LED = 13;
const int Sensor = A0;

int seviye;
const int esik = 500;

void setup()
{
  pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode (LED, OUTPUT);
Serial.begin(9600);
}

void loop() {
seviye = analogRead(Sensor);
Serial.println(seviye);
if (seviye > esik)
{
   digitalWrite(7, HIGH);
          digitalWrite(8, HIGH);
          digitalWrite(9, HIGH);
          digitalWrite(10, HIGH);
          digitalWrite(11, HIGH);
          digitalWrite(12, HIGH);
digitalWrite (LED, HIGH);
delay (1000);
 digitalWrite(7, LOW);
       digitalWrite(8, LOW);
       digitalWrite(9, LOW);
       digitalWrite(10, LOW);
       digitalWrite(11, LOW);
       digitalWrite(12, LOW);
digitalWrite (LED, LOW);
}
else
{
digitalWrite(LED, LOW);
}
}
