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

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2); /* how large is the screen columns, rows*/
  lcd.print("hello world!");
  delay(1000);

}

void loop() 
{ 
  // scroll 13 positions (string length) to the left 
  // to move it offscreen left:
  for (int pos = 0; pos < 13; pos++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(150);
  }

  // scroll 29 positions (string length + display length) to the right
  // to move it offscreen right:
  for (int positionCounter = 0; positionCounter < 29; positionCounter++) {
    // scroll one position right:
    lcd.scrollDisplayRight(); 
    // wait a bit:
    delay(150);
  }

  // scroll 16 positions (display length + string length) to the left
  // to move it back to center:
  for (int positionCounter = 0; positionCounter < 16; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft(); 
    // wait a bit:
    delay(150);
  }

  delay(1000);
}


