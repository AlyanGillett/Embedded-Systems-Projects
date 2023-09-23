//Alyan Gillett Arduino Projects
/* This Tinkercad involves creating a servo motor control system using an Arduino and a potentiometer. 
The potentiometer allows users to manipulate the servo motor's position, enabling control over its movement and direction.
*/

#include <Servo.h>

Servo myservo;
int potPin = A0; // Analog input pin for the potentiometer

void setup() {
  myservo.attach(9); // Pin 9 for controlling the servo
}

void loop() {
  int potValue = analogRead(potPin);
  int servoAngle = map(potValue, 0, 1023, 0, 180); // Map potentiometer value to servo angle

  myservo.write(servoAngle); // Set the servo angle

  delay(15); // Delay for stability
}
