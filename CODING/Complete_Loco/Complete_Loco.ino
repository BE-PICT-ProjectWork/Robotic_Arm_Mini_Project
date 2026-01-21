#include <PS4Controller.h>
#include <Servo.h>

Servo servo;
const int servoPin = 13;

int motor1Pin1 = 27; 
int motor1Pin2 = 26;
int motor2Pin1 = 32;
int motor2Pin2 = 33;
int motor3Pin1 = 19; 
int motor3Pin2 = 18;
int motor4Pin1 = 3;
int motor4Pin2 = 2;

const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
// int dutyCycle = 200; 

void setup() 
{
  Serial.begin(115200);
  PS4.begin("48:89:e7:cd:91:59");
  Serial.println("\t Ready .. ");
  servo.attach(servoPin);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(motor3Pin1, OUTPUT);
  pinMode(motor3Pin2, OUTPUT);
  pinMode(motor4Pin1, OUTPUT);
  pinMode(motor4Pin2, OUTPUT);
  ledcSetup(pwmChannel, freq, resolution);
  Serial.print("\n\t Let's Go ..");
}

void loop() 
{
  if (PS4.isConnected()) 
  {
    Serial.println("\t Connected !! ");
    
    if(PS4.RStickX()<=0 && PS4.RStickX()>=-4 && PS4.RStickY()<=4 && PS4.RStickY()>=-4)
    {
        // No Motion .. 
        // Stop the DC motor
        Serial.println("\t No Motion ..");
        Serial.println("\t Motor Stopped .. ");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, LOW);
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, LOW);
        digitalWrite(motor3Pin1, LOW);
        digitalWrite(motor3Pin2, LOW);
        digitalWrite(motor4Pin1, LOW);
        digitalWrite(motor4Pin2, LOW);
        delay(100);
    }
    else if(PS4.RStickY()>=2 && PS4.RStickY()<=128 && PS4.RStickX()<=81 && PS4.RStickX()>=-105)
    {
        // Move Forward .. 
        // Move the DC motor forward at maximum speed
        Serial.println("\t Moving Forwards .. ");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH); 
        digitalWrite(motor3Pin1, LOW);
        digitalWrite(motor3Pin2, HIGH); 
        digitalWrite(motor4Pin1, LOW);
        digitalWrite(motor4Pin2, HIGH); 
        delay(100);
    }
    else if(PS4.RStickY()<=2 && PS4.RStickY()>=-128 && PS4.RStickX()<=82 && PS4.RStickX()>=-105)
    {
        // Move Backward .. 
        // Move DC motor backwards at maximum speed
        Serial.println("\t Moving Backwards .. ");
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        digitalWrite(motor3Pin1, HIGH);
        digitalWrite(motor3Pin2, LOW); 
        digitalWrite(motor4Pin1, HIGH);
        digitalWrite(motor4Pin2, LOW); 
        delay(100);
    }
    else if(PS4.RStickY()>=-96 && PS4.RStickY()<=96 && PS4.RStickX()<=-1 && PS4.RStickX()>=-128)
    {
        // Move Left .. 
        Serial.println("\t Moving Left ..");
        digitalWrite(motor1Pin1, LOW);
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        digitalWrite(motor3Pin1, LOW);
        digitalWrite(motor3Pin2, HIGH); 
        digitalWrite(motor4Pin1, HIGH);
        digitalWrite(motor4Pin2, LOW); 
        delay(100);
    }
    else if(PS4.RStickY()>=-115 && PS4.RStickY()<=115 && PS4.RStickX()>=-1 && PS4.RStickX()<=128)
    {
        // Move Right .. 
        Serial.println("\t Moving Right ..");
        digitalWrite(motor1Pin1, HIGH);
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        digitalWrite(motor3Pin1, HIGH);
        digitalWrite(motor3Pin2, LOW); 
        digitalWrite(motor4Pin1, LOW);
        digitalWrite(motor4Pin2, HIGH); 
        delay(100);
    }
    else
    {
        Serial.println("\t Eat 5-Star , Do Nothing ..");
    }

    if(PS4.Circle())
    {
      for(int posDegree = 0; posDegree < 360; posDegree++)
      {
        Serial.println("\t Base Servo - 360 degrees .. ");
        servo.write(posDegree);
        delay(10);
      }
    }

    // if(PS4.R1())
    // {
    //   for(int posDegrees = 0; posDegrees <= 180; posDegrees++) 
    //   {
    //     servo2.write(posDegrees);
    //     delay(10);
    //     // Serial.println(posDegrees);
    //   }
    // }
    // if(PS4.L1())
    // {
    //   for(int posDegrees = 180; posDegrees >= 0; posDegrees--) 
    //   {
    //       servo2.write(posDegrees);
    //       delay(10);
    //       // Serial.println(posDegrees);
    //   }
    // }

    // Servo servo1;
    // const int servoPin = 4;
    // const int frequency = 200; // Hz

    // servo1.attach(
    //     servoPin, 
    //     Servo::CHANNEL_NOT_ATTACHED, 
    //     Servo::DEFAULT_MIN_ANGLE, 
    //     Servo::DEFAULT_MAX_ANGLE, 
    //     Servo::DEFAULT_MIN_PULSE_WIDTH_US, 
    //     Servo::DEFAULT_MAX_PULSE_WIDTH_US, 
    //     frequency
    // );

  }
  delay(500);
}
