#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x3f, 16, 2);

//for sound
int DA = A0; 
int ses1 = 200;//
int sesdegeri = 0;
int led_status=0;
int counter_clamp=0;
int control=0;

//for temp
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
dht11 DHT11;

//for button
int led1=5;
int buton1=6;
int buton1Durum;
int led1Durum=0;
int x=0;
void setup(){
lcd.begin();
lcd.backlight();
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(buton1, INPUT);
Serial.begin(1000000);
}
 
void loop(){

  
int chk = DHT11.read(DHT11PIN); 
lcd.setCursor(0,0);
lcd.print("Temp:");
lcd.setCursor(5,0);
lcd.print((int)DHT11.temperature);
lcd.setCursor(7,0);
lcd.print(".C");

//Sensörden Veri Alma
 sesdegeri = analogRead(DA); 
 if(sesdegeri>ses1){
   Serial.println(sesdegeri);
 }
 
//button control
  buton1Durum=digitalRead(buton1);
  if(buton1Durum==HIGH && x==0){
    x=1;
    if(led1Durum==0){
      led1Durum=1;}
    else if(led1Durum==1){
      led1Durum=0;}
  }
  else if(buton1Durum==LOW && x==1){
    x=0;
  }
 
  if (led1Durum==1){
      lcd.setCursor(13,0);
    lcd.print("M.1");
    digitalWrite(led1, HIGH);
  }
  else if(led1Durum==0){
    lcd.setCursor(13,0);
    lcd.print("M.2");
    digitalWrite(led1, LOW);
  }

  //sescontrol
if(sesdegeri > ses1){
 counter_clamp++;
 
 if(counter_clamp==2){
  if(led_status==0){
    led_status=1;
  }else if(led_status==1){
    led_status=0;
  }
   counter_clamp=0;
   control=1;
 }
 
}

if(led_status==1 && control==1){
  
  for(int i=7;i<=13;i++){
          digitalWrite(i, HIGH);
         delay(175);
          }
          lcd.setCursor(0,1);
          lcd.print("LED_POSITIVE");
          control=0;
}else if(led_status==0 && control==1){
  
  for(int i=7;i<=13;i++){
          digitalWrite(i, LOW);
        delay(175);
          }
    lcd.setCursor(0,1);
    lcd.print("LED_NEGATIVE");
     control=0;
}
 
}
