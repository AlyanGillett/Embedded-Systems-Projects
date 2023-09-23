//Alyan Gillett Arduino Projects
/* Using a push button with digital inputs in order to turn an LED on and off. 
Pressing the button turns it on, and pressing the other button turns it off. */
int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;
void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

void loop() 
{
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }

  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}
