int motor1Pin1 = 27; 
int motor1Pin2 = 26;
int motor2Pin1 = 32;
int motor2Pin2 = 33;
int motor3Pin1 = a; 
int motor3Pin2 = b;
int motor4Pin1 = c;
int motor4Pin2 = d;

const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
// int dutyCycle = 200;
 
void setup() 
{
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);

  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  // ledcAttachPin(enable1Pin, pwmChannel);
 
  Serial.begin(115200);
  Serial.print("\n\t Testing DC Motor...");
}
 
void loop()
{
  // Move the DC motor forward at maximum speed
  Serial.println("Moving Forward");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH); 
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH); 
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, HIGH); 
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, HIGH); 
  delay(5000);
 
  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
  delay(1000);
 
  // Move DC motor backwards at maximum speed
  Serial.println("Moving Backwards");
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW); 
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, HIGH);
  digitalWrite(motor3Pin2, LOW); 
  digitalWrite(motor4Pin1, HIGH);
  digitalWrite(motor4Pin2, LOW); 
  delay(5000);
 
  // Stop the DC motor
  Serial.println("Motor stopped");
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  digitalWrite(motor3Pin1, LOW);
  digitalWrite(motor3Pin2, LOW);
  digitalWrite(motor4Pin1, LOW);
  digitalWrite(motor4Pin2, LOW);
  delay(1000);
 
  // Move DC motor forward with increasing speed
  // digitalWrite(motor1Pin1, HIGH);
  // digitalWrite(motor1Pin2, LOW);
  // while (dutyCycle <= 255){
  //   ledcWrite(pwmChannel, dutyCycle);   
  //   Serial.print("Forward with duty cycle: ");
  //   Serial.println(dutyCycle);
  //   dutyCycle = dutyCycle + 5;
  //   delay(500);
  // }
  // dutyCycle = 200;
  // delay(1000);
}

// #include <L293D.h>

// #define MOTOR_A      1   // motor pin a
// #define MOTOR_B      2   // motor pin b

// #define PWM_MOTOR_FREQUENCY   200
// #define PWM_MOTOR_RESOLUTION    8

// // Create motor object using given pins
// L293D motor(MOTOR_A, MOTOR_B);

// void setup() {  
//     // begin --> true false, enables disables PWM, use given frequency and resolution
//     motor.begin(true, PWM_MOTOR_FREQUENCY, PWM_MOTOR_RESOLUTION);
//     // Speed -100%...0..100%
//     motor.SetMotorSpeed(100);
// }

// void loop() {
//   delay(100);
// }

// // ..

// int a=8;
// int b=9;

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinmode(a,OUTPUT);
//   pinmode(b,OUTPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(a,LOW);
//   digitalWrite(b,LOW);
//   delay(2000);
//   digitalWrite(a,LOW);
//   digitalWrite(b,HIGH);
//   delay(5000);
//   digitalWrite(a,HIGH);
//   digitalWrite(b,LOW);
//   delay(5000);
  
//   delay(1000);
// }

// // ..
// if (PS4.Right()) Serial.println("Right Button");
    // if (PS4.Down()) Serial.println("Down Button");
    // if (PS4.Up()) Serial.println("Up Button");
    // if (PS4.Left()) Serial.println("Left Button");
    // if (PS4.Square()) Serial.println("Square Button");
    // if (PS4.Cross()) Serial.println("Cross Button");
    // if (PS4.Circle()) Serial.println("Circle Button");
    // if (PS4.Triangle()) Serial.println("Triangle Button");
    // if (PS4.UpRight()) Serial.println("Up Right");
    // if (PS4.DownRight()) Serial.println("Down Right");
    // if (PS4.UpLeft()) Serial.println("Up Left");
    // if (PS4.DownLeft()) Serial.println("Down Left");
    // if (PS4.L1()) Serial.println("L1 Button");
    // if (PS4.R1()) Serial.println("R1 Button");
    // if (PS4.L2()) {
    //   Serial.printf("L2 button at %d\n", PS4.L2Value());
    // }
    // if (PS4.R2()) {
    //   Serial.printf("R2 button at %d\n", PS4.R2Value());
    // }
    // if (PS4.LStickX()) {
    //   Serial.printf("Left Stick x at %d\n", PS4.LStickX());
    // }
    // if (PS4.LStickY()) {
    //   Serial.printf("Left Stick y at %d\n", PS4.LStickY());
    // }
    // if (PS4.RStickX()) {
    //   Serial.printf("Right Stick x at %d\n", PS4.RStickX());
    // }
    // if (PS4.RStickY()) {
    //   Serial.printf("Right Stick y at %d\n", PS4.RStickY());
    // }
