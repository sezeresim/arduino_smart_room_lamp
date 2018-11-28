int DA = A0; // A0 pinini DA değişkenine aktarıyoruz
int ses1 = 100;//

int sesdegeri = 0;
int led_status=0;

void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
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
 
}
