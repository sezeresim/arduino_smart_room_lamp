#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.
LiquidCrystal_I2C lcd(0x3f, 16, 2);

int DA = A0; // A0 pinini DA değişkenine aktarıyoruz
int ses1 = 100;//

dht11 DHT11;
void setup()
{

lcd.begin();
lcd.backlight();
Serial.begin(9600); // Seri iletişimi başlatıyoruz.
Serial.println("Arduinoturkiye.com DHT11 Test Programi");
pinMode(3, OUTPUT);
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
  
  //Açıp Kapama Döngüsü
  if (sesdegeri > ses1 && led_status==0) { //Eğer algılanan ses seviyesi belirlediğimiz değerden büyükse
          digitalWrite(3, HIGH);//3.pindeki ledimize güç veriyor
          led_status=1;//led durumunu 1 konumuna çalışır duruma getirip kapanma durumunda kullanmak için
  }else if(sesdegeri > ses1 && led_status==1){
       digitalWrite(3, LOW);//3.pindeki ledimize güç kesiyor
       led_status=0;
  }
  //Açıp Kapama Döngüsü-end
// 2 saniye bekliyoruz. 2 saniyede bir veriler ekrana yazdırılacak.
//delay(500);

}
