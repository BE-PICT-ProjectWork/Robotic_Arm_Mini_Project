

// SG90 : SERVOMIN  150 && SERVOMAX  600  
// MG995 : 
// 

// #include <Arduino.h>

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>

#define PCA9685_ADDR 0x40
#define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096) //175 
#define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096) //310

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

int servonum = 1;
Servo myservo;

void setup() 
{
  Serial.begin(9600);
  Serial.println("\n 8 channel PWM test!");

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(50);  // This is the maximum PWM frequency

  Wire.setClock(270000);
  myservo.attach(A10);
}

void loop() 
{
  
  // Serial.println(servonum);
  // myservo.write(0);

  for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) 
  {
    // Serial.println("In One .. ");
    pwm.setPWM(servonum, 0, pulselen);
    delay(5);
  }
  delay(1000);
  
  for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) 
  {
    // Serial.println("In Two .. ");
    pwm.setPWM(servonum, 0, pulselen);
    delay(5);
  }
  delay(1000);

  // servonum += 1;
  // if (servonum >= 5)
  // {
  //   servonum = 0; // Testing the first 5 servo channels
  // }
}

// .. //

  // joystickXVal = analogRead(joystickXPin) ; //Reading the X axis pin of the joystick
  // joystickXVal = map (joystickXVal, 0, 1023, SERVOMIN, SERVOMAX); //Scaling the analog value into a readable value for the library
  // pwm.setPWM(servoNum1, 0, joystickXVal); //Setting the Servo in pin 0 (servoNum1) to move according to the Scaled Value
  // delay(15);

  // joystickYVal = analogRead(joystickYPin) ; //Reading the Y axis pin of the joystick
  // joystickYVal = map (joystickYVal, 0, 1023, SERVOMIN, SERVOMAX); //Scaling the analog value into a readable value for the library
  // pwm.setPWM(servoNum2, 0, joystickYVal); //Setting the Servo in pin 1 (servoNum2) to move according to the Scaled Value
  // delay(15);

// .. // 

// #include <Wire.h>
// #include <Adafruit_PWMServoDriver.h>
// #include <Servo.h>

// #define PCA9685_ADDR 0x40
// #define SERVO_MIN_PULSE_WIDTH 600
// #define SERVO_MAX_PULSE_WIDTH 2400
// #define NUM_SERVOS 6

// Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
// Servo myservo;

// void setup() 
// {
//   Serial.begin(9600);
//   Serial.println("\n 16 channel PWM test ! ");
//   pwm.begin();
//   pwm.setOscillatorFrequency(27000000);
//   Wire.setClock(270000);
//   myservo.attach(A10);  
//   pwm.setPWMFreq(50); // Set PWM frequency for servos (50Hz is typical)
// }

// void loop()
// {
//   // Move each servo from 0 to 180 degrees
//   for (int servoNum = 0; servoNum < NUM_SERVOS; servoNum++) 
//   {
//     setServoPosition(servoNum, 0); // Move servo to 0 degrees
//     delay(500); // Delay for 0.5 seconds
//     setServoPosition(servoNum, 180); // Move servo to 180 degrees
//     delay(500); // Delay for 0.5 seconds
//   }
// }

// // Function to set servo position
// void setServoPosition(int servoNum, int position) 
// {
//   int pulseWidth = map(position, 0, 180, SERVO_MIN_PULSE_WIDTH, SERVO_MAX_PULSE_WIDTH);
//   pwm.setPWM(servoNum, 0, pulseWidth);
// }
