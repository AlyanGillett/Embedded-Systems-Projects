//Alyan Gillett Arduino Projects
#include <LedControl.h>

// Define the pins for MAX7219 module
#define DIN_PIN 11
#define CS_PIN 10
#define CLK_PIN 13

LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1); // Initialize the MAX7219 module

const int potPin = A0; // Analog pin for the potentiometer

// Ball variables
int ballX = 3; // Initial X position of the ball (centered)
int ballY = 0; // Initial Y position of the ball (closer to the top)
int ballSpeedX = 1; // Speed of the ball in the X direction
int ballSpeedY = 1; // Speed of the ball in the Y direction
bool ballDirectionX = true; // Ball direction in X (true for right, false for left)
bool ballDirectionY = true; // Ball direction in Y (true for down, false for up)

void setup() {
  lc.shutdown(0, false); // Wake up the MAX7219 module
  lc.setIntensity(0, 8); // Set the brightness (0-15)
  lc.clearDisplay(0); // Clear the display

  pinMode(potPin, INPUT); // Set the potentiometer pin as input
}

void loop() {
  int potValue = analogRead(potPin); // Read the potentiometer value
  int maxPositions = 8; // Number of positions to move the dots (from far left to far right)
  int ledColumn = map(potValue, 0, 1023, 0, maxPositions); // Map potentiometer value to LED column

  // Clear the entire display
  lc.clearDisplay(0);

  // Calculate the starting position for the three dots based on the potentiometer value
  int paddlePosition = maxPositions - ledColumn - 2; // Adjusted to center the paddle

  // Display the three LEDs together for the paddle
  for (int i = 0; i < 3; i++) {
    lc.setLed(0, 7, paddlePosition + i, true);
  }

  // Clear the ball's previous position
  lc.setLed(0, ballY, ballX, false);

  // Move the ball in the X and Y directions
  ballX += ballDirectionX ? ballSpeedX : -ballSpeedX;
  ballY += ballDirectionY ? ballSpeedY : -ballSpeedY;

  // Check if the ball hit the left or right edge and change direction
  if (ballX <= 0 || ballX >= 7) {
    ballDirectionX = !ballDirectionX;
  }

  // Check if the ball hit the top or bottom edge and change direction
  if (ballY <= 0 || ballY >= 7) {
    ballDirectionY = !ballDirectionY;
  }

  // Display the ball at its new position
  lc.setLed(0, ballY, ballX, true);

  delay(100); // Adjust the delay as needed for the ball speed
}
