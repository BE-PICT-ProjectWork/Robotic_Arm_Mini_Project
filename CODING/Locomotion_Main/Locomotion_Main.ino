#include "CytronMotorDriver.h"
#include <PS4Controller.h>

// Define motor pins
#define MOTOR_A_PWM_PIN 18
#define MOTOR_A_DIR_PIN 19
#define MOTOR_B_PWM_PIN 2
#define MOTOR_B_DIR_PIN 4
#define MOTOR_C_PWM_PIN 12
#define MOTOR_C_DIR_PIN 13
#define MOTOR_D_PWM_PIN 27
#define MOTOR_D_DIR_PIN 14

// Initialize motor drivers
CytronMD motorA(PWM_DIR, MOTOR_A_PWM_PIN, MOTOR_A_DIR_PIN);
CytronMD motorB(PWM_DIR, MOTOR_B_PWM_PIN, MOTOR_B_DIR_PIN);
CytronMD motorC(PWM_DIR, MOTOR_C_PWM_PIN, MOTOR_C_DIR_PIN);
CytronMD motorD(PWM_DIR, MOTOR_D_PWM_PIN, MOTOR_D_DIR_PIN);

// Define PS4 controller object
PS4Controller ps4;

void setup()
{
  Serial.begin(9600);
  
  // Initialize motor drivers
  // motorA.begin();
  // motorB.begin();
  // motorC.begin();
  // motorD.begin(); 

  // Initialize PS4 controller
  ps4.begin("48:89:e7:cd:91:59");
}

void loop() 
{
  // Read PS4 controller input
  // ps4.read();

  int x = ps4.LStickX();
  int y = ps4.LStickY();
  int z = ps4.RStickX();

  // Calculate motor speeds based on controller input
  int m1_speed = 2 * (y - x - z);
  int m2_speed = 2 * (x + y - z);
  int m3_speed = 2 * (x + y + z);
  int m4_speed = 2 * (y - x + z);

  // Set motor directions
  // motorA.setDirection(m1_speed >= 0 ? FORWARD : BACKWARD);
  // motorB.setDirection(m2_speed >= 0 ? FORWARD : BACKWARD);
  // motorC.setDirection(m3_speed >= 0 ? FORWARD : BACKWARD);
  // motorD.setDirection(m4_speed >= 0 ? FORWARD : BACKWARD);

  // Set motor speeds
  motorA.setSpeed(abs(m1_speed));
  motorB.setSpeed(abs(m2_speed));
  motorC.setSpeed(abs(m3_speed));
  motorD.setSpeed(abs(m4_speed));

  // Update motor outputs
  // motorA.drive();
  // motorB.drive();
  // motorC.drive();
  // motorD.drive();

  // Add optional delay to control loop rate
  delay(100);
}
