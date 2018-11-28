int led1=9;
int buton1=8;
int buton1Durum;
int led1Durum=0;

int buton2Durum;
int led2Durum=0;
int led2=10;
int buton2=11;

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

  
  buton2Durum=digitalRead(buton2);
  if(buton2Durum==HIGH && x==0){
    x=1;
    if(led2Durum==0) led2Durum=1;
    else if(led2Durum==1) led2Durum=0;
  }
  else if(buton2Durum==LOW && x==1){
    x=0;
  }
 
  if (led2Durum==1){
    digitalWrite(led2, HIGH);
  }
  else{
    digitalWrite(led2, LOW);
  }
}
