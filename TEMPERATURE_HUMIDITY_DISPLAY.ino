//Alyan Gillett Arduino Projects
/* This Tinkercad involves creating a temperature and humidity monitoring system 
using an Arduino, a DHT11 sensor, and a LiquidCrystal display. 
The system continuously retrieves temperature and humidity data from the DHT11 sensor, 
converting the temperature reading into Fahrenheit and then presenting both 
temperature and humidity values on the LCD screen. 
Moreover,  it provides a proper display with real-time updates of the temperature and humidity, 
with a 2-second pause between readings which can be seen on the Serial Monitor data stream. */

#include <DHT11.h>
#include <LiquidCrystal.h>

DHT11 dht11(2);
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup()
{
    lcd.begin(16, 2);
    Serial.begin(115200);
}

void loop()
{
    float humidity = dht11.readHumidity();
    float temperatureC = dht11.readTemperature();
    float temperatureF = (temperatureC * 9/5) + 32;

    if (temperatureC != -1 && humidity != -1)
    {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Temp.: ");
        lcd.print(temperatureF);
        lcd.write(0xDF); // Print the degree symbol (°F).

        lcd.setCursor(0, 1);
        lcd.print("Humidity: ");
        lcd.print(humidity);
        lcd.print(" %");

        Serial.print("Temperature: ");
        Serial.print(temperatureF);
        Serial.print(" F, Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    }
    else
    {
        lcd.clear();
        lcd.print("Error reading data");
        Serial.println("Error reading data");
    }

    delay(2000);
}
