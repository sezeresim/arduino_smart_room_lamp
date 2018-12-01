#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
LiquidCrystal_I2C lcd(0x3f, 16, 2);
//sıcaklık
int lm35Pin = A2;
unsigned long zaman = 0, eskizaman = 0;
//ses için
int ses_sensoru = A0;
int alkis = 0;
long algilama_araligi_baslangic = 0;
long algilama_araligi = 0;
boolean isik_durumu = false;
int esik=500;
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
//lcd control
int sahip=0;
//for button

int buton=3;
int durum=0;
int butondeger=0;
//for button 2
int buton2=4;
int durum2=0;
int butondeger2=0;

void setup() {
 lcd.begin();
lcd.backlight();
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);
pinMode(buton, INPUT);
pinMode(buton2,INPUT);
Serial.begin(1000000);
}
 
void loop() {
 
if(sahip==0){
   lcd.setCursor(0,1);
 lcd.print("Cemre Eren");
 lcd.setCursor(10,0);
     lcd.print("/");
     lcd.setCursor(11,0);
     lcd.print(durum2);
     lcd.setCursor(12,0);
     lcd.print("/");
     lcd.setCursor(13,0);
   lcd.print("V.1");
    lcd.setCursor(13,1);
            lcd.print("OFF");
            lcd.setCursor(0,0);
lcd.print("Temp:");
lcd.setCursor(7,0);
lcd.print(".C");
 sahip=1;
}

  zaman = millis();
  int fark = zaman - eskizaman;
  
  if (fark > 2000){
    int sicaklikVolt = analogRead(lm35Pin);
    int sicaklikC = sicaklikC = sicaklikVolt / 9.31; 
    lcd.setCursor(5, 0);
    lcd.print(sicaklikC);
    eskizaman = zaman;
  }
 



//button 1
  butondeger=digitalRead(buton);
  if(butondeger==HIGH && durum==0){
    durum=1;
    lcd.setCursor(13,0);
   lcd.print("V.2");
    delay(100);
  }else if(butondeger==HIGH && durum==1){
     lcd.setCursor(13,0);
   lcd.print("V.1");
    durum=0;
     delay(100);
  }
  
  //button 2
 butondeger2=digitalRead(buton2);
  if(butondeger2==HIGH && durum2==0){
    
    esik=550;
    durum2=1;
    delay(100);
  }else if(butondeger2==HIGH && durum2==1){
    esik=600;
    durum2=2;
    delay(100);
  }else if(butondeger2==HIGH && durum2==2){
    esik=650;
    durum2=3;
    delay(100);
  }else if(butondeger2==HIGH && durum2==3){
    esik=500;
    durum2=0;
    delay(100);
  }
   
   lcd.setCursor(11,0);
   lcd.print(durum2);
  
  int sensor_durumu = analogRead(ses_sensoru);
 Serial.println(sensor_durumu);
  //Modlar
  if(durum==0){
    
     if (sensor_durumu >esik)
  {
    if (alkis == 0)
    {
      algilama_araligi_baslangic = algilama_araligi = millis();
      alkis++;
    }
    else if (alkis > 0 && millis()-algilama_araligi >= 50)
    {
      algilama_araligi = millis();
      alkis++;
    }
  }
 
  if (millis()-algilama_araligi_baslangic >= 400)
  {
    if (alkis == 2)
    {
      if (!isik_durumu)
        {
          isik_durumu = true;
          for(int i=5;i<=10;i++){
            digitalWrite(i, HIGH);
            lcd.setCursor(13,1);
            lcd.print(" ON");
          }
          
        }
        else if (isik_durumu)
        {
          isik_durumu = false;
           for(int i=5;i<=10;i++){
            digitalWrite(i, LOW);
            lcd.setCursor(13,1);
            lcd.print("OFF");
          }
        }
    }
    alkis = 0;
  }

  }
  if(durum==1){
    if (sensor_durumu >= ses1) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(5, HIGH);
  }
  else {
    digitalWrite(5, LOW);
  }

   if (sensor_durumu >= ses2) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(6, HIGH);
  }
  else {
    digitalWrite(6, LOW);
  }
  
   if (sensor_durumu >= ses3) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(7, HIGH);
  }
  else {
    digitalWrite(7, LOW);
  }
   if (sensor_durumu >= ses4) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(8, LOW);
  }
   if (sensor_durumu >= ses5) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(9, HIGH);
  }
  else {
    digitalWrite(9, LOW);
  }
    if (sensor_durumu >= ses6) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
    digitalWrite(10, HIGH);
  }
  else {
    digitalWrite(10, LOW);
  }
  
  }

}
