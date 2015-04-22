/*
    info about the board: https://learn.sparkfun.com/tutorials/redboard-hookup-guide

    motor control code taken on 4/15/2015 from
    https://learn.adafruit.com/adafruit-arduino-lesson-13-dc-motors/arduino-code

    flex sensor code:
    https://learn.sparkfun.com/tutorials/sik-experiment-guide-for-arduino---v32/experiment-9-using-a-flex-sensor

    photo sensor code:
    https://learn.adafruit.com/photocells/using-a-photocell
*/

// ANALOG IN pins
const int lightSensor = 2;

// ANALOG OUT pins
const int leftMotor = 5;
const int rightMotor = 6;
const int speaker = 8;

// motor variables
// must be >= 0 && <= 255
int leftSpeed = 55;
int rightSpeed = 55;

// light sensor variables
int lightValue;
int baseLightValue;
const int THRESHOLD = 40;

// speaker variables
int freq = 440;
int duration = 2;

void setup()
{
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  // initialize serial communications at 9600 bps
  Serial.begin(9600);

  baseLightValue = analogRead(lightSensor);
}


void loop()
{
  analogWrite(leftMotor, leftSpeed);
  analogWrite(rightMotor, rightSpeed);

  lightValue = analogRead(lightSensor);

  //Serial.print("Analog reading = ");
  Serial.print(lightValue);     // the raw analog reading

  if ((lightValue - baseLightValue) > THRESHOLD) {
    analogWrite(leftMotor, leftSpeed);
    analogWrite(rightMotor, rightSpeed);
  } else {
    analogWrite(leftMotor, 0);
    analogWrite(rightMotor, 0);
    tone(speaker, freq, duration);
  }

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading.
  delay(2);
}
