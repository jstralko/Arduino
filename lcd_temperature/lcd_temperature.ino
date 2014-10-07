#include <LiquidCrystal.h>

/*
 * Help from: http://arduino.cc/en/Tutorial/LiquidCrystalScroll
 *
 * Arduino Pin 12 - RS Pin LCD
 *             11 - EN
 *             5  - D4
 *             4  - D5
 *             3  - D6
 *             2  - D7
 */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int sensor_pin = A0;
int sensor_value = 0;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2); /* how large is the screen columns, rows*/
  lcd.print("hello world!");
  delay(1000);

}

void loop() 
{ 
  lcd.clear();
  sensor_value = analogRead(sensor_pin);
  float voltage = (sensor_value / 1024.0) * 5.0;
  float celsius = (voltage - 0.5) * 100;
  float fahrenheit = (celsius * 1.800) + 32.00;
  lcd.print("Temperature is  ");
  lcd.setCursor(/*col*/0,/*row*/1);
  lcd.print(celsius);
  lcd.print("C (");
  lcd.print(fahrenheit);
  lcd.print("F)");
  delay(1000);
}


