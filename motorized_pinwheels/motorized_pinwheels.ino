
/*
 * Needs based on how you configured your board.
 * For example switch to connected to the 2# PIN 
 * and the motor_pin (via the transistor) is 
 * connected to the #9 PIN.
 */
const int switch_pin = 2;
const int motor_pin = 9;

int switch_state = 0;

void setup() 
{
  
  //Serial.begin(9600);
  /* 
   * POV from the board. 
   *  - The boards was to read (input) 
   * from the switch_pin to determine if 
   * its pressed
   */
   pinMode(switch_pin, INPUT);
   /*
    * Likewise the motor_pin will be 
    * written (OUTPUT) to activate the 
    * motor. 
    */
   pinMode(motor_pin, OUTPUT); 
}

void loop() 
{
    switch_state = digitalRead(switch_pin);
    
    digitalWrite(motor_pin, switch_state);
}
