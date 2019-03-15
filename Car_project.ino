#include<IRremote.h>
#define echoPin 9
#define trigPin 10
#define buzzerPin 11

int esikdeger=50;
int led10=12;
int deger10;
int maxR=35;
int minR=0;

int solileri=2;
int solgeri=3;
int saggeri=4;
int sagileri=5;
int led1=7;
int led2=8;
int isik=A2;
#define OK 0xFF38C7
#define BUTON1 0xFFA25D
#define BUTON2 0xFF629D
#define BUTON3 0xFFE21D
#define BUTON4 0xFF22DD
#define BUTON5 0xFF02FD
#define BUTON6 0xFFC23D
#define BUTON7 0xFFE01F
#define BUTON8 0xFFA857
#define BUTON9 0xFF906F
#define BUTON0 0xFF9867
#define SAG 0xFF5AA5
#define SOL 0xFF10EF
#define YUKARI 0xFF18E7
#define ASAGI 0xFF4AB5
IRrecv irrecv(6);
decode_results results;

void setup() {
pinMode(led10,OUTPUT);
  pinMode( trigPin,OUTPUT);
 pinMode(echoPin,INPUT);
 pinMode(buzzerPin,OUTPUT);

   pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  irrecv.enableIRIn();
pinMode(solileri,OUTPUT);
pinMode(solgeri,OUTPUT);
pinMode(saggeri,OUTPUT);
pinMode(sagileri,OUTPUT);
Serial.begin(9600);

}

void loop() {
deger10=analogRead(A5);
if(deger10>esikdeger){
  digitalWrite(led10,HIGH);
}
else
digitalWrite(led10,LOW);
}
  long duration,distance;
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=duration/58.2;
  if(distance<=maxR && distance>=minR)
  {
digitalWrite(buzzerPin,HIGH);
delay(20);
digitalWrite(buzzerPin,LOW);
delay(20);

  }
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
if(results.value==SAG){
  digitalWrite(solileri,HIGH);
  digitalWrite(solgeri,LOW);
digitalWrite(sagileri,LOW);
digitalWrite(saggeri,LOW);
}
if(results.value==OK){
  digitalWrite(saggeri,LOW);
   digitalWrite(solgeri,LOW);
digitalWrite(sagileri,LOW);
digitalWrite(solileri,LOW);
}
if(results.value==SOL){
  digitalWrite(saggeri,LOW);
   digitalWrite(solgeri,LOW);
digitalWrite(sagileri,HIGH);
digitalWrite(solileri,LOW);
}
if(results.value==YUKARI){
  digitalWrite(saggeri,LOW);
   digitalWrite(solgeri,LOW);
digitalWrite(sagileri,HIGH);
digitalWrite(solileri,HIGH);
}
if(results.value==ASAGI){
  digitalWrite(saggeri,HIGH);
   digitalWrite(solgeri,HIGH);
digitalWrite(sagileri,LOW);
digitalWrite(solileri,LOW);
      
  }
  irrecv.resume();
}
int deger=analogRead(isik);
  
  if (deger<980){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW); 
  }
  else {
    digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  }

}


  

  
