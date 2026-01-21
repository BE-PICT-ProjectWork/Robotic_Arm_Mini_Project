
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define PCA9685_ADDR 0x40

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

void setup() 
{
  Serial.begin(9600);
  Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(50); // Set PWM frequency for servos (50Hz is typical)
}

void loop() 
{
  // Sweep the servo from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle++)
   {
    pwm.setPWM(0, 0, map(angle, 0, 180, 100, 500)); // Adjust servo pulse width for proper range
    delay(500); // Adjust delay for servo speed
  }
  
  // Sweep the servo from 180 to 0 degrees
  for (int angle = 180; angle >= 0; angle--) {
    pwm.setPWM(0, 0, map(angle, 0, 180, 100, 500)); // Adjust servo pulse width for proper range
    delay(25); // Adjust delay for servo speed
  }
}


// #include <Wire.h>
// #include <Adafruit_PWMServoDriver.h>

// #define PCA9685_ADDR 0x40
// #define SERVO_MIN_PULSE_WIDTH 600
// #define SERVO_MAX_PULSE_WIDTH 2400
// #define NUM_SERVOS 6

// Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// void setup() {
//   Serial.begin(9600);
//   Wire.begin();
//   pwm.begin();
//   pwm.setPWMFreq(50); // Set PWM frequency for servos (50Hz is typical)
// }

// void loop() {
//   // Move each servo from 0 to 180 degrees
//   for (int servoNum = 0; servoNum < NUM_SERVOS; servoNum++) 
//   {
//     Serial.println("\nServo-Num");Serial.print(servoNum);
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
  
//   Serial.println("\nPulse-Width");Serial.print(pulseWidth);
//   pwm.setPWM(servoNum, 0, pulseWidth);
// }

// #include <Wire.h>
// #include <Adafruit_PWMServoDriver.h>

// Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// #define SERVOMIN  150 // This is the 'minimum' pulse length count (out of 4096)
// #define SERVOMAX  600 // This is the 'maximum' pulse length count (out of 4096)
// // #define USMIN  600 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
// // #define USMAX  2400 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
// #define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates

// int servonum = 0;

// void setup() {
//   Serial.begin(9600);
//   Serial.println("\n 8 channel Servo test !");

//   pwm.begin();
//   // pwm.setOscillatorFrequency(27000000);
//   pwm.setPWMFreq(SERVO_FREQ);  // Analog servos run at ~50 Hz updates

//   delay(10);
// }

// // void setServoPulse(uint8_t n, double pulse) 
// // {
// //   double pulselength;  
// //   pulselength = 1000000;   // 1,000,000 us per second
// //   pulselength /= SERVO_FREQ;   // Analog servos run at ~60 Hz updates
// //   Serial.print(pulselength); Serial.println(" us per period"); 
// //   pulselength /= 4096;  // 12 bits of resolution
// //   Serial.print(pulselength); Serial.println(" us per bit"); 
// //   pulse *= 1000000;  // convert input seconds to us
// //   pulse /= pulselength;
// //   Serial.println(pulse);
// //   pwm.setPWM(n, 0, pulse);
// // }

// // void loop()
// // {
// //   Serial.println(servonum);
// //   for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
// //     pwm.setPWM(servonum, 0, pulselen);
// //   }

// //   delay(500);

// //   for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
// //     pwm.setPWM(servonum, 0, pulselen);
// //   }

// //   delay(500);

// //   for (uint16_t microsec = USMIN; microsec < USMAX; microsec++) {
// //     pwm.writeMicroseconds(servonum, microsec);
// //   }

// //   delay(500);
  
// //   for (uint16_t microsec = USMAX; microsec > USMIN; microsec--) {
// //     pwm.writeMicroseconds(servonum, microsec);
// //   }

// //   delay(500);

// //   servonum++;
// //   if (servonum > 6) servonum = 0; // Testing the first 8 servo channels
// // }

// //..//

// void loop() 
// {
//     for( int angle=0; angle<180; angle +=10)
//     {
//       for(int i=0; i<7; i++)
//         {      
//             pwm.setPWM(i, 0, angleToPulse(angle) );
//             // board1.setPWM(i, 0, angleToPulse(angle) );
//         }
//     }
//   delay(5000); 
// }

// int angleToPulse(int ang)
// {
//    int pulse = map(ang, 0, 180, SERVOMIN,SERVOMAX); 
//    Serial.print("Angle: ");Serial.print(ang);
//    Serial.print(" pulse: ");Serial.println(pulse);
//    return pulse;
// }

// //..//

