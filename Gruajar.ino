#include <Servo.h>

#define trigPin 5
#define echoPin 4



Servo servo1;
Servo servo2;



void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(9);
  servo2.attach(10);
 
}

void loop(){
  
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    int pos1 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1);
    int pos2 = data.substring(0, data.indexOf(',')).toInt();
    data = data.substring(data.indexOf(',') + 1);
    servo1.write(pos1);
    servo2.write(pos2);
  }
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  long distance = (duration * 0.034)/2;

  Serial.println(distance);
  delay(500);
  
  
}
