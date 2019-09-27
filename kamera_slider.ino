int steppin=4;
int dirpin=3;
int value;
int buton =5;

void setup() {

  pinMode(5,INPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  

}

void loop() {
  int x=digitalRead(buton);
  int deger=analogRead(A0);
  value=map(deger,0,1023,900,5000);
   if(x == 1){
    digitalWrite(3,LOW);
  digitalWrite(steppin,HIGH);
  delayMicroseconds(value);
  digitalWrite(steppin,LOW);
  delayMicroseconds(value);
  }
  else {
    digitalWrite(3,HIGH);
  digitalWrite(steppin,HIGH);
  delayMicroseconds(value);
  digitalWrite(steppin,LOW);
  delayMicroseconds(value);
    
  }
  

}
