//Alyan Gillett Arduino Projects
/*Using an RGB LED to create a cycle of 3 different colors: red, green, and blue. This will be done by starting off in a red state, fading to green, fading to blue, then ending back in red.*\
// defines pins
#define BLUE 3
#define GREEN 5
#define RED 6

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

//Define Variables
int redValue;
int greenValue;
int blueValue;

//main loop
void loop() {
#define delayTime 10  //fading time between colors
  redValue = 255;     //choose a value between 1 and 255 to change the color
  greenValue = 0;
  blueValue = 0;

  for (int i = 0; i < 255; i += 1)  // fades out of red bringing green full when i = 255
  {
    redValue -= 1;
    greenValue += 1;
    analogWrite(RED, redValue);      // (RED, 255 - redValue)
    analogWrite(GREEN, greenValue);  // (GREEN, 255 - greenValue)
    delay(delayTime);
  }
  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for (int i = 0; i < 255; i += 1)  // fades out of red bringing green full when i = 255
  {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(GREEN, greenValue);  //(GREEN, 255 - greenValue )
    analogWrite(BLUE, blueValue);    // (BLUE, 255 - blueValue)
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 0;
  blueValue = 255;

  for (int i = 0; i < 255; i += 1)  // fades out of red bringing green full when i = 255
  {
    blueValue -= 1;
    redValue += 1;
    analogWrite(BLUE, blueValue);  //(Blue, 255 - blueValue)
    analogWrite(RED, redValue);    //(RED, 255 - redValue)
    delay(delayTime);
  }
}
