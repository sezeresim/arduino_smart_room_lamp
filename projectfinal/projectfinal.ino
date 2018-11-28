#include <LiquidCrystal_I2C.h>
#include <Wire.h> 
#include <dht11.h> // dht11 kütüphanesini ekliyoruz.
#define DHT11PIN 2 // DHT11PIN olarak Dijital 2"yi belirliyoruz.

LiquidCrystal_I2C lcd(0x3f, 16, 2);
dht11 DHT11;
void setup()
{

lcd.begin();
lcd.backlight();
Serial.begin(9600); // Seri iletişimi başlatıyoruz.
Serial.println("Arduinoturkiye.com DHT11 Test Programi");
}
 
void loop(){
int chk = DHT11.read(DHT11PIN); 
lcd.setCursor(0,0);
lcd.print("Temp:");
lcd.setCursor(5,0);
lcd.print((int)DHT11.temperature);
lcd.setCursor(7,0);
lcd.print(".C");
// 2 saniye bekliyoruz. 2 saniyede bir veriler ekrana yazdırılacak.
delay(500);

}
