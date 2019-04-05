#include <Servo.h>

Servo servo1;
Servo servo2;

int buttonState = 0;
boolean trigger = false;

void setup() {
  Serial.begin(9600);
  
  pinMode(9, INPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  servo1.attach(10);
  servo2.attach(11);

  servo2.write(0);
  delay(1000);
  servo2.write(90);
}

void loop() {
  int PotPosition;
  int servo1Position;
  
  PotPosition = analogRead(A0);
  servo1Position = map(PotPosition, 0, 1023, 0, 180);

  servo1.write(servo1Position);

  buttonState = digitalRead(A1);
  servo2.write(0);
  if(buttonState == HIGH){
    servo2.write(90);
  }
  
  delay(50); 
}
