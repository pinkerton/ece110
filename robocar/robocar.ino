/* 
info about the board: https://learn.sparkfun.com/tutorials/redboard-hookup-guide

motor control code taken on 4/15/2015 from
https://learn.adafruit.com/adafruit-arduino-lesson-13-dc-motors/arduino-code

flex sensor code:
https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-9-using-a-flex-sensor
*/

// ANALOG IN pins
const int leftFlexSensor = 0;
const int rightFlexSensor = 1;

// ANALOG OUT pins
const int leftMotor = 7;
const int rightMotor = 8;

// must be >= 0 && <= 255
int leftSpeed = 200;
int rightSpeed = 200;

int leftFlexValue;
int rightFlexValue;
 
void setup() 
{ 
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  //analogWrite(leftMotor, leftSpeed);
  //analogWrite(rightMotor, rightSpeed);
  
  leftFlexValue = analogRead(leftFlexSensor);
  rightFlexValue = analogRead(rightFlexSensor);
  
  Serial.print("left flex: " + leftFlexValue);
  Serial.print("right flex: " + rightFlexValue);
  
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading. necessary??
  delay(2);
}
