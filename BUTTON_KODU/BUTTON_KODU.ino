
int buton1=6;
int buton1Durum;
int led1Durum=0;

int x=0;

void setup(){
  pinMode(led1, OUTPUT);
  pinMode(buton1, INPUT);
   pinMode(led2, OUTPUT);
  pinMode(buton2, INPUT);
  
}

void loop(){
  buton1Durum=digitalRead(buton1);
  if(buton1Durum==HIGH && x==0){
    x=1;
    if(led1Durum==0) led1Durum=1;
    else if(led1Durum==1) led1Durum=0;
  }
  else if(buton1Durum==LOW && x==1){
    x=0;
  }
 
  if (led1Durum==1){
    digitalWrite(led1, HIGH);
  }
  else{
    digitalWrite(led1, LOW);
  }

  
  
}
