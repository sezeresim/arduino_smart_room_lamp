#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x3f, 16, 2);

//for sound
int DA = A0; 
int sesvalue = 90;//
int sesdegeri = 0;
int led_status=0;
int counter_clamp=0;
int control=0;
//ses2
int ses1 = 30;//analog ses seviyesi
int ses2 = 40;
int ses3 = 50;
int ses4 = 80;
int ses5 = 90;
int ses6 = 100;
int ses7 = 120;
int ses8 = 150;
int ses9 = 180;
//for temp
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
dht11 DHT11;

//for button

int buton=3;
int durum=0;
int butondeger=0;
//for button 2
int buton2=4;
int durum2=0;
int butondeger2=0;
void setup(){
lcd.begin();
lcd.backlight();
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
pinMode(buton, INPUT);
pinMode(buton2,INPUT);
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
 
     Serial.println(sesdegeri);

 if(sesdegeri>sesvalue){
 }
 
//button control
   butondeger=digitalRead(buton);
  if(butondeger==HIGH && durum==0){
    durum=1;
    delay(100);
  }else if(butondeger==HIGH && durum==1){
    durum=0;
     delay(100);
  }

//button 2
 butondeger2=digitalRead(buton2);
  if(butondeger2==HIGH && durum2==0){
    durum2=1;
    delay(100);
  }else if(butondeger2==HIGH && durum2==1){
    durum2=2;
    delay(100);
  }else if(butondeger2==HIGH && durum2==2){
    durum2=3;
    delay(100);
  }else if(butondeger2==HIGH && durum2==3){
    durum2=0;
    delay(100);
  }
  Serial.println(durum2);
  switch(durum2){
    case 0:
     lcd.setCursor(10,0);
     lcd.print("/");
     lcd.setCursor(11,0);
     lcd.print(durum2);
     lcd.setCursor(12,0);
     lcd.print("/");
     break;
     case 1:
     lcd.setCursor(10,0);
     lcd.print("/");
     lcd.setCursor(11,0);
     lcd.print(durum2);
     lcd.setCursor(12,0);
     lcd.print("/");
     break;
     case 2:
     lcd.setCursor(10,0);
     lcd.print("/");
     lcd.setCursor(11,0);
     lcd.print(durum2);
     lcd.setCursor(12,0);
     lcd.print("/");
     break;
     case 3:
     lcd.setCursor(10,0);
     lcd.print("/");
     lcd.setCursor(11,0);
     lcd.print(durum2);
     lcd.setCursor(12,0);
     lcd.print("/");
     break;
     
  }

  //Serial.println(durum);
  //sescontrol
if(sesdegeri > sesvalue){
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


 if(durum==1){
   lcd.setCursor(13,0);
   lcd.print("V.2");
   if (sesdegeri >= ses1) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(5, LOW);
  }

   if (sesdegeri >= ses2) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
  
   if (sesdegeri >= ses3) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
   if (sesdegeri >= ses4) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }
   if (sesdegeri >= ses5) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(9, LOW);
  }
    if (sesdegeri >= ses6) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(10, HIGH);
  }
  else {
    digitalWrite(10, LOW);
  }
    if (sesdegeri >= ses7) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(11, HIGH);
  }
  else {
    digitalWrite(11, LOW);
  }
    if (sesdegeri >= ses8) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(12, HIGH);
  }
  else {
    digitalWrite(12, LOW);
  }
    if (sesdegeri >= ses9) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(13, HIGH);
  }
  else {
    digitalWrite(13, LOW);
  }
  }else{
   lcd.setCursor(13,0);
   lcd.print("V.1");
   if(led_status==1 && control==1){
  
  for(int i=5;i<=13;i++){
          digitalWrite(i, HIGH);
         delay(175);
          }
          lcd.setCursor(0,1);
          lcd.print("Cemre Eren");
          lcd.setCursor(13,1);
          lcd.print("ON");
          control=0;
}else if(led_status==0 && control==1){
  
  for(int i=5;i<=13;i++){
          digitalWrite(i, LOW);
        delay(175);
          }
    lcd.setCursor(0,1);
    lcd.print("Cemre Eren");
      lcd.setCursor(13,1);
          lcd.print("OFF");
     control=0;
}
}

}

