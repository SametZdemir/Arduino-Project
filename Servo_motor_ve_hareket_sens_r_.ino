#include<Servo.h>
Servo motor;
int sensor=8;
int servo=9;
int hareket;

void setup() {
  pinMode(sensor,INPUT);
  motor.attach(servo);
}

void loop() {
  hareket=digitalRead(sensor);
  if(hareket==HIGH){
  motor.write(150);
delay(300);
motor.write(30);
delay(300);
motor.write(150);
delay(300);
motor.write(30);
delay(300);
  }
else
motor.write(90);
 
}
