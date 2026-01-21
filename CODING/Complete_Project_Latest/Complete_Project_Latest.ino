
#include <Adafruit_PWMServoDriver.h>
#include <Wire.h>
#include <CytronMotorDriver.h>
#include <PS4Controller.h>

// Motor pin definitions
#define MOTOR_A_PWM_PIN 18
#define MOTOR_A_DIR_PIN 19
#define MOTOR_B_PWM_PIN 2
#define MOTOR_B_DIR_PIN 15
#define MOTOR_C_PWM_PIN 12
#define MOTOR_C_DIR_PIN 13
#define MOTOR_D_PWM_PIN 27
#define MOTOR_D_DIR_PIN 14

// Servo control constants
#define SERVO_PWM_FREQUENCY 50
#define SERVO_TOTAL_CHANNELS 6
#define SERVO_STEP_DELAY 16

// Function prototypes
void constrainMotorSpeeds(int& M1_pwm, int& M2_pwm, int& M3_pwm, int& M4_pwm);
void setMotorSpeedAndDirection(int M1_pwm, int M2_pwm, int M3_pwm, int M4_pwm);
void moveServos();
void moveServoSmoothly(int servoNum, uint16_t start, uint16_t end);

// Initialize motor instances
CytronMD motorA(PWM_DIR, MOTOR_A_PWM_PIN, MOTOR_A_DIR_PIN);
CytronMD motorB(PWM_DIR, MOTOR_B_PWM_PIN, MOTOR_B_DIR_PIN);
CytronMD motorC(PWM_DIR, MOTOR_C_PWM_PIN, MOTOR_C_DIR_PIN);
CytronMD motorD(PWM_DIR, MOTOR_D_PWM_PIN, MOTOR_D_DIR_PIN);

// Initialize PS4 controller instance
PS4Controller ps4;
// Initialize servo driver instance
Adafruit_PWMServoDriver pwm;

void setup() {
  Serial.begin(115200);

  // Initialize motor drivers
  motorA.setSpeed(0);
  motorB.setSpeed(0);
  motorC.setSpeed(0);
  motorD.setSpeed(0);

  // Initialize PS4 controller
  ps4.begin("48:e7:da:44:75:08"); //d8:3a:dd:c5:e5:7a

  // Initialize PWM for servo
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_PWM_FREQUENCY);
}

void loop() {
  if (ps4.isConnected()) {
    // Read PS4 joystick values
    int leftStickX = ps4.LStickX();  // Left joystick X-axis for left-right motion
    int rightStickY = ps4.RStickY(); // Right joystick Y-axis for forward-backward motion
    int leftStickY = ps4.LStickY();  // Left joystick Y-axis for translation
    int rightStickX = ps4.RStickX(); // Right joystick X-axis for rotation

    // Calculate motor speeds based on joystick inputs
    int M1_pwm = rightStickY - rightStickX + leftStickX;
    int M2_pwm = rightStickY + rightStickX - leftStickX;
    int M3_pwm = rightStickY + rightStickX + leftStickX;
    int M4_pwm = rightStickY - rightStickX - leftStickX;

    // Constrain motor speeds to valid range
    constrainMotorSpeeds(M1_pwm, M2_pwm, M3_pwm, M4_pwm);

    // Set motor speeds and directions
    setMotorSpeedAndDirection(M1_pwm, M2_pwm, M3_pwm, M4_pwm);

    // Move servos based on PS4 controller inputs
    moveServos();
  }
}

// Function to constrain motor speeds within valid range
void constrainMotorSpeeds(int& M1_pwm, int& M2_pwm, int& M3_pwm, int& M4_pwm) 
{
  M1_pwm = constrain(M1_pwm, 0, 64); //255
  M2_pwm = constrain(M2_pwm, 0, 64); //255
  M3_pwm = constrain(M3_pwm, 0, 64); //255
  M4_pwm = constrain(M4_pwm, 0, 64); //255
}

// Function to set motor speeds and directions
void setMotorSpeedAndDirection(int M1_pwm, int M2_pwm, int M3_pwm, int M4_pwm) 
{
  // Initialize direction variables for motors
  int M1_dir, M2_dir, M3_dir, M4_dir;

  // Determine motor direction based on PWM values
  M1_dir = (M1_pwm >= 0) ? 0 : 1;
  M2_dir = (M2_pwm >= 0) ? 0 : 1;
  M3_dir = (M3_pwm >= 0) ? 0 : 1;
  M4_dir = (M4_pwm >= 0) ? 0 : 1;

  // Set motor speeds
  if(M1_pwm>10 && M2_pwm>10 && M3_pwm>10 && M4_pwm>10)
  {
    motorA.setSpeed(abs(M1_pwm));
    motorB.setSpeed(abs(M2_pwm));
    motorC.setSpeed(abs(M3_pwm));
    motorD.setSpeed(abs(M4_pwm));
  }
  else
  {
    motorA.setSpeed(0);
    motorB.setSpeed(0);
    motorC.setSpeed(0);
    motorD.setSpeed(0);
  }
}

// Function to move servos based on PS4 controller inputs
void moveServos() {
  static unsigned long lastServoMoveTime = 0;

  if (millis() - lastServoMoveTime > 100) {
    lastServoMoveTime = millis();

    // Check PS4 controller inputs and move servos accordingly
    if (ps4.Circle()) {
      moveServoSmoothly(0, 250, 275);
    } else if (ps4.Cross()) {
      moveServoSmoothly(0, 325, 300);
    } else if (ps4.Up()) {
      moveServoSmoothly(1, 200, 325);
    } else if (ps4.Down()) {
      moveServoSmoothly(1, 325, 200);
    } else if (ps4.Square()) {
      moveServoSmoothly(2, 250, 275);
    } else if (ps4.Triangle()) {
      moveServoSmoothly(2, 350, 325);
    } else if (ps4.Left()) {
      moveServoSmoothly(3, 225, 375);
    } else if (ps4.Right()) {
      moveServoSmoothly(3, 375, 225);
    } else if (ps4.L1()) {
      moveServoSmoothly(4, 250, 255);
    } else if (ps4.L2()) {
      moveServoSmoothly(4, 350, 345);
    } else if (ps4.R1()) {
      moveServoSmoothly(5, 75, 575);
    } else if (ps4.R2()) {
      moveServoSmoothly(5, 575, 75);
    } else {
      // Stop servo movement
      // pwm.setPWM(1,375,375);
      // pwm.setPWM(4,375,375);
      for (int servoNum = 0; servoNum < SERVO_TOTAL_CHANNELS; servoNum++) {
        pwm.setPWM(servoNum, 0, 0);
      }
    }
  }
}

// Function to move servo smoothly from 'start' to 'end' position
void moveServoSmoothly(int servoNum, uint16_t start, uint16_t end) {
  uint16_t step = start < end ? 1 : -1;
  for (uint16_t pulseLen = start; pulseLen != end; pulseLen += step) {
    pwm.setPWM(servoNum, 0, pulseLen);
    delay(SERVO_STEP_DELAY);
  }
}

