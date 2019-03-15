#define trig 2
#define echo 3
#define led 9

 float mesafe=0.00,sure=0.00;
void setup() {
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);
pinMode(led,OUTPUT);
Serial.begin(9600);
  }

void loop() {
digitalWrite(trig,HIGH);
delayMicroseconds(1000);
digitalWrite(trig,LOW);

sure=pulseIn(echo,HIGH);
mesafe=sure/58.20;


if(mesafe<30.00)
digitalWrite(led,HIGH);
digitalWrite(led,LOW);

}
