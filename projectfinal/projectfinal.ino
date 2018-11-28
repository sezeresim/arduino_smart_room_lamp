#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
LiquidCrystal_I2C lcd(0x3f, 16, 2);

int DA = A0; 
int ses1 = 300;//

int sesdegeri = 0;
int led_status=0;

dht11 DHT11;
void setup(){
lcd.begin();
lcd.backlight();
pinMode(7, OUTPUT);

Serial.begin(500000);
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
  //Açıp Kapama Döngüsü
  if (sesdegeri > ses1 && led_status==0) { 
          digitalWrite(7, HIGH);
          led_status=1;
          lcd.setCursor(0,1);
           lcd.print("LED_POSITIVE");
            
  }else if(sesdegeri > ses1 && led_status==1){
       digitalWrite(7, LOW);
       led_status=0;
         lcd.setCursor(0,1);
         lcd.print("LED_NEGATIVE");
      
       
  }
  //Açıp Kapama Döngüsü-end
  
}
