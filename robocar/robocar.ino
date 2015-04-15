/* 
info about the board: https://learn.sparkfun.com/tutorials/redboard-hookup-guide

motor control code taken on 4/15/2015 from
https://learn.adafruit.com/adafruit-arduino-lesson-13-dc-motors/arduino-code

flex sensor code:
https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-9-using-a-flex-sensor
*/

// ANALOG IN pins
const int leftLightSensor = 0;
const int rightLightSensor = 1;

// ANALOG OUT pins
const int leftMotor = 5;
const int rightMotor = 6;

// must be >= 0 && <= 255
int leftSpeed = 255;
int rightSpeed = 255;
 
void setup() 
{ 
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  // initialize serial communications at 9600 bps
  Serial.begin(9600);
} 
 
 
void loop() 
{ 
  analogWrite(leftMotor, leftSpeed);
  analogWrite(rightMotor, rightSpeed);
  
  leftLightValue = analogRead(leftLight);
  rightLightValue = analogRead(rightLight);
  
  Serial.print("left light sensor: ");
  Serial.println(leftLightValue);
  
  Serial.print("right light sensor: ");
  Serial.println(rightLightValue);
  
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading. necessary??
  delay(2);
}
