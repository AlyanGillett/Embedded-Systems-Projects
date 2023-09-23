//Alyan Gillett Arduino Projects
/* Use eight large LEDS with arduino by using a chip called a 74HC595 Serial to parallel Converter. This process is so we don’t have to give up 8 output pins on the UNO. */
int tDelay = 100;
int latchPin = 11;      // (11) ST_CP [RCK] on 74HC595
int clockPin = 9;      // (9) SH_CP [SCK] on 74HC595
int dataPin = 12;     // (12) DS [S1] on 74HC595

byte leds = 0;
// this first function to turn them off, from right to left (least significant)
void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds); //LSBFIRST starts from the least significant Byte, that corresponds to 8th pinout 
   digitalWrite(latchPin, HIGH);
}
// this second function is to turn them off
void updateShiftRegister2() 
{ 
   digitalWrite(latchPin, HIGH);
   shiftOut(dataPin, clockPin, LSBFIRST, leds); //if we start with MSBFIRST in this function, then it would start from the most significant, that is the 1st pinout.
   digitalWrite(latchPin, LOW);
}

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
   Serial.begin(9600);
}


/*

void loop() 
{
 
  leds = 0;
  updateShiftRegister2(1);
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister2(1);
    delay(500);
  }
  leds = 0;
  updateShiftRegister2(0);
  delay(500);
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister2(0);
    delay(500);
  }
  

  
  for (int i = 0; i < 8; i++)
  {
    bitSet(leds, i);
    updateShiftRegister2();
    delay(500);

  
  
  
}


*/
  
  


void loop() 
{
   leds = 0;
  updateShiftRegister();
  for (int i = 0; i < 8; i++)
  {
    delay(tDelay);
    bitSet(leds, i); //bitset sets the byte of each led to on
    updateShiftRegister();   
  
    
    
  } 
 
  for (int i = 0; i < 8; i++)
  {
	
    bitClear(leds, i); //bitclear sets the byte of each led to off
    updateShiftRegister2();  
    delay(tDelay);
  }
}
