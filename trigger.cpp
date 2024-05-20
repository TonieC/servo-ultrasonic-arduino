// This code will trigger the servo motor to move when the Ultrasonic Sensor senses object nearby
#include <Servo.h>

Servo myServo;
const int trigPin = 7;
const int echoPin = 8;
long duration;
int distance;

void setup() {
  myServo.attach(13);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance <= 10) {
    myServo.write(0);
  } else if (distance > 10 && distance <= 20) {
    myServo.write(90);
  } else if (distance > 20) {
    myServo.write(180);
  }

  delay(5000);
}
