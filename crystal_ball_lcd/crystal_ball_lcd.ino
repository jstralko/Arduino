#include <LiquidCrystal.h>

/*
 * Arduino Pin 12 - RS Pin LCD
 *             11 - EN
 *             5  - D4
 *             4  - D5
 *             3  - D6
 *             2  - D7
 */
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int switch_pin = 6;
int switch_state = 0;
int prev_switch_state = 0;
int reply;

void setup() 
{
  Serial.begin(9600);
   lcd.begin(16,2); /* how large is the screen columns, rows*/
   pinMode(switch_pin, INPUT);
   lcd.print("ASk the");
   lcd.setCursor(0,1); /* first column on the second line*/
   lcd.print("Crystal Ball!");
}

void loop() 
{
   switch_state = digitalRead(switch_pin);
   if (switch_state != prev_switch_state) {
     if (switch_state == LOW) {
       reply = random(8);
       lcd.clear();
       lcd.setCursor(0,0);
       lcd.print("The ball says:");
       lcd.setCursor(0,1);
       
       switch(reply) {
        case 0:
          lcd.print("Yes");
        break;
        case 1:
          lcd.print("Most Likely");
        break;
        case 2:
          lcd.print("Certainly");
        break;
        case 3:
          lcd.print("Outlook good");
        break;
        case 4:
          lcd.print("Unsure");
        break;
        case 5:
          lcd.print("Ask again");
        break;
        case 6:
          lcd.print("Doubtful");
        break;
        case 7:
          lcd.print("No");
        break; 
       }
     } 
  }
  prev_switch_state = switch_state;  
}
