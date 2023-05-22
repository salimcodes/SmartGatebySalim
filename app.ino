#include <Servo.h>
Servo Gate;
int angle = 0;

int trigPin = 9;
int echoPin = 10;
int buzzPin = 4;

int servoPin = 11;
// RGB codes
int redLed1 = 3;
int greenLed1 = 5;

int redLed2 = 6;
int greenLed2 = 7;

long duration;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(redLed1, OUTPUT);
  pinMode(greenLed1, OUTPUT);

  pinMode(redLed2, OUTPUT);
  pinMode(greenLed2, OUTPUT);
 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Gate.attach(servoPin);

}




void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print("Distance ");
  Serial.println(distance);

  if (distance < 20){
    Gate.write(90);
    digitalWrite(redLed1, LOW);
    digitalWrite(redLed2, LOW);
    digitalWrite(greenLed1, HIGH);
    digitalWrite(greenLed2, HIGH);
   
    tone(buzzPin, 2000);
   
    delay(3000);
   
    Gate.write(0);
    digitalWrite(redLed1, HIGH);
    digitalWrite(redLed2, HIGH);
    digitalWrite(greenLed1, LOW);
    digitalWrite(greenLed2, LOW);
    noTone(buzzPin);
   
  }
  else if (distance > 20){
     Gate.write(0);
    digitalWrite(redLed1, HIGH);
    digitalWrite(redLed2, HIGH);
    digitalWrite(greenLed1, LOW);
    digitalWrite(greenLed2, LOW);
    noTone(buzzPin);
   
    }

    delay(1000);
  }
