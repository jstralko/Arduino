const int control_pin1 = 2;
const int control_pin2 = 3;
const int enable_pin = 9;
const int direction_switch_pin = 4;
const int on_off_switch_state_pin  = 5;
const int pot_pin = A0; //ANALOG pin #A0

int on_off_switch_state = 0;
int previous_on_off_switch_state = 0;
int direction_switch_state = 0;
int previous_direction_switch_state = 0;

int motor_enabled = 0;
int motor_speed = 0;
int motor_direction = 0;

void setup()
{
  
  Serial.begin(9600);
  
  pinMode(direction_switch_pin, INPUT);
  pinMode(on_off_switch_state_pin, INPUT);
  pinMode(control_pin1, OUTPUT);
  pinMode(control_pin2, OUTPUT);
  pinMode(enable_pin, OUTPUT);
   
  digitalWrite(enable_pin, LOW);
}

void loop()
{
   on_off_switch_state = digitalRead(on_off_switch_state_pin);
   delay(1);
   direction_switch_state = digitalRead(direction_switch_pin);
   
   motor_speed = analogRead(pot_pin)/4;
   
   /*
    * This acts like a switch, you need to click it on again to
    * switch state
    * To turn on the motor click the button once.  To turn it off
    */
   if (on_off_switch_state != previous_on_off_switch_state) {
     if (on_off_switch_state == HIGH) {
        motor_enabled = !motor_enabled;
     }
   }
   
   if (direction_switch_state != previous_direction_switch_state) {
      if (direction_switch_state == HIGH) {
         motor_direction = !motor_direction;
      } 
   }
   /*
   Serial.print("on_off_state: ");
   Serial.print(on_off_switch_state);
   Serial.print(" direction_state: ");
   Serial.print(direction_switch_state);
   Serial.print(" motor_speed: ");
   Serial.println(motor_speed);
   */
   
   if (motor_direction == 1) {
      digitalWrite(control_pin1, HIGH);
      digitalWrite(control_pin2, LOW); 
   } else {
      digitalWrite(control_pin1, LOW);
      digitalWrite(control_pin2, HIGH); 
   }
   
   analogWrite(enable_pin, motor_enabled ? motor_speed : 0); 
   
   previous_direction_switch_state = direction_switch_state;
   previous_on_off_switch_state = on_off_switch_state;
}
