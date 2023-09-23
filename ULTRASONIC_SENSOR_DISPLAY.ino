//Alyan Gillett Arduino Projects
/* This project uses an Arduino Uno board, an ultrasonic sensor, and an LCD display to create a distance measurement device. 
The ultrasonic sensor emits sound waves and measures the time it takes for the sound waves to bounce back after hitting an object. 
By calculating the time delay, the distance to the object can be determined. */

#include <LiquidCrystal.h>

// Initialize the LCD library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

const int trigPin = 11;
const int echoPin = 10;

void setup() {
  // Set up the LCD
  lcd.begin(16, 2);
  
  // Set up the ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the LCD screen
  lcd.clear();
  
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the pulse duration
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters and meters
  float cm = duration * 0.034 / 2;
  float m = cm / 100.0;
  
  // Print the distance on the LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(cm);
  lcd.print(" cm");
  
  lcd.setCursor(0, 1);
  lcd.print("           "); // Clear the second row
  lcd.setCursor(0, 1);
  lcd.print("         ");
  lcd.print(m);
  lcd.print(" m");
  
  delay(1000);
}
