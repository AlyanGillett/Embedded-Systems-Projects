//Alyan Gillett Arduino Projects
/*This Tinkercad involves creating a climate control system with real-time monitoring 
and fan automation using an Arduino board, a DHT11 sensor, and a LiquidCrystal display. 
The code initializes the necessary libraries and pins for the components, sets a 
temperature threshold, and controls a fan based on the temperature readings. 
Nonetheless, it continuously reads temperature and humidity data from the sensor, 
illustrates it on the LCD screen, and turns on the fan if the temperature exceeds 
the specified threshold, helping to maintain the desired temperature. 
Additionally, the code includes functions for controlling the fan's direction and speed. */

#include <DHT.h>
#include <LiquidCrystal.h>

#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

const float fanThreshold = 80.0; // Adjust this threshold as needed (Fan threshold in Fahrenheit)
bool fanOn = false;              // Fan default position as off

// Motor FAN connections
int fanSwitch = 3;  // Turns on and off the fan
int in3 = 5;  // Use for directional rotations
int in4 = 4;  // Use for directional rotations

void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  dht.begin();

  // Set all the motor control pins for Motor Fan to outputs
  pinMode(fanSwitch, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  // Turn off Fan - Initial state
  digitalWrite(fanSwitch, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void loop() {
  // Temperature readings
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();
  float temperatureF = (temperatureC * 9/5) + 32;

  if (!isnan(temperatureC) && !isnan(humidity)) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temp.: "); // Print temperature
    lcd.print(temperatureF);
    lcd.write(0xDF); // Print the degree symbol (°F).
    lcd.print("F");

    lcd.setCursor(0, 1);
    lcd.print("Hum:"); // Print humidity
    lcd.print(humidity, 1);
    lcd.print(" %");

    lcd.setCursor(9, 1);
    lcd.print("Fan:");  // Print fan state
    if (temperatureF >= fanThreshold) {
      lcd.print("On ");
      fanOn = true;
      speedControl(); // Turn on the fan
    } else if (temperatureF < fanThreshold) {
        if (fanOn) {
          // Gradually decelerate the fan over a 5-second period
          lcd.print("Off");
          for (int i = 255; i >= 0; --i) {
            analogWrite(fanSwitch, i);
            delay(20);
            
          }

          // Ensure the fan is completely off
          analogWrite(fanSwitch, 0);
          digitalWrite(fanSwitch, LOW); // Turn off the fan

          fanOn = false; // Update fan state
        }

        lcd.print("Off");
      }



    Serial.print("Temperature: ");
    Serial.print(temperatureF);
    Serial.print(" F, Humidity: ");
    Serial.print(humidity);
    Serial.print(" %, Fan: ");
    Serial.println(fanOn ? "On" : "Off");
  } else {
    lcd.clear();
    lcd.print("Error reading data");
    Serial.println("Error reading data");
  }

  delay(1000);
}

// This function lets you control spinning direction of Motor fan
void directionControl() {
  // Now change motor direction for Motor B
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

// This function lets you control speed of Motor fan
void speedControl() {
  // Turn on Motor B
  digitalWrite(fanSwitch, HIGH);
  
  directionControl(); // Set the direction
  
  // Accelerate from zero to maximum speed for Motor fan
  for (int i = 0; i < 255; i++) {
    analogWrite(fanSwitch, i);
  }
}
