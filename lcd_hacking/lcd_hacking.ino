#include <LiquidCrystal.h>

/*
 * Help from: http://arduino.cc/en/Tutorial/LiquidCrystalScroll
 * Arduino Pin 12 - RS Pin LCD
 *             11 - EN
 *             5  - D4
 *             4  - D5
 *             3  - D6
 *             2  - D7
 */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  Serial.begin(9600);
   lcd.begin(16,2); /* how large is the screen columns, rows*/
   
   
}

void loop() 
{ 
}
