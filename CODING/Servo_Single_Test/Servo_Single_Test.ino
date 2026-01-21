#include <Servo.h>

const int x=360;

static const int servoPin = 4;
Servo myServo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("\t Ready .. ");
  myServo.attach(servoPin);
  Serial.println("\t Servo On .. ");
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int pos=0;pos<=x;pos++)
  {
    Serial.print("\n\t Position : \t");
    Serial.print(pos);
    myServo.write(pos);
    delay(20);
  }
  delay(1000);
  for(int pos=x;pos>=0;pos--)
  {
    Serial.print("\n\t Position : \t");
    Serial.print(pos);
    myServo.write(pos);
    delay(20);
  }
  delay(1000);
}

// ..

// #include <Adafruit_PWMServoDriver.h>

// Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

// void setup() {
//   // Set the servo angle to 90 degrees
//   pwm.begin();
//   pwm.setPWMFreq(50);
//   pwm.setPWM(0, 0, 1500);
// }

// void loop() {
//   // Set the servo angle to 0 degrees
//   pwm.setPWM(0, 0, 1000);
//   delay(1000);

//   // Set the servo angle to 90 degrees
//   pwm.setPWM(0, 0, 1500);
//   delay(1000);

//   // Set the servo angle to 180 degrees
//   pwm.setPWM(0, 0, 2000);
//   delay(1000);
// }

// ..
