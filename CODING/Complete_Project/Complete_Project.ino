
#include <PS4Controller.h>
// #include <Servo.h>

// static const int servosPins[3] = {18, 19, 21};
// Servo servos[3];

// void setServos(int degrees) 
// {
//     for(int i = 0; i < 3; ++i) 
//     {
//         servos[i].write((degrees + (35 * i)) % 180);
//     }
// }

// int motor1Pin1 = 27; 
// int motor1Pin2 = 26;
// int motor2Pin1 = 32;
// int motor2Pin2 = 33;
// int motor3Pin1 = 19; 
// int motor3Pin2 = 18;
// int motor4Pin1 = 4;
// int motor4Pin2 = 2;

// const int freq = 30000;
// const int pwmChannel = 0;
// const int resolution = 8;
// int dutyCycle = 200; 

void setup() 
{
  Serial.begin(115200);
  PS4.begin("dc:21:5c:39:af:e3");
  Serial.println("\t Ready .. ");
  // for(int i = 0; i < 3; ++i) 
  // {
  //   if(! (servos[i].attach(servosPins[i]))) 
  //   {
  //     Serial.print("\n\t Servo ");
  //     Serial.print(i);
  //     Serial.print(" attach error .. ");
  //   }
  // }
  // pinMode(motor1Pin1, OUTPUT);
  // pinMode(motor1Pin2, OUTPUT);
  // pinMode(motor2Pin1, OUTPUT);
  // pinMode(motor2Pin2, OUTPUT);
  // pinMode(motor3Pin1, OUTPUT);
  // pinMode(motor3Pin2, OUTPUT);
  // pinMode(motor4Pin1, OUTPUT);
  // pinMode(motor4Pin2, OUTPUT);
  // ledcSetup(pwmChannel, freq, resolution);
  Serial.print("\n\t Let's Go ..");
}

void loop() 
{
  if (PS4.isConnected()) 
  {
    Serial.println("\t Connected !! ");
    
    // if(PS4.RStickX()<=0 && PS4.RStickX()>=-4 && PS4.RStickY()<=4 && PS4.RStickY()>=-4)
    // {
    //     // No Motion .. 
    //     // Stop the DC motor
    //     Serial.println("\t No Motion ..");
    //     Serial.println("\t Motor Stopped .. ");
    //     digitalWrite(motor1Pin1, LOW);
    //     digitalWrite(motor1Pin2, LOW);
    //     digitalWrite(motor2Pin1, LOW);
    //     digitalWrite(motor2Pin2, LOW);
    //     digitalWrite(motor3Pin1, LOW);
    //     digitalWrite(motor3Pin2, LOW);
    //     digitalWrite(motor4Pin1, LOW);
    //     digitalWrite(motor4Pin2, LOW);
    //     delay(100);
    // }
    // else if(PS4.RStickY()>=2 && PS4.RStickY()<=128 && PS4.RStickX()<=81 && PS4.RStickX()>=-105)
    // {
    //     // Move Forward .. 
    //     // Move the DC motor forward at maximum speed
    //     Serial.println("\t Moving Forwards .. ");
    //     digitalWrite(motor1Pin1, LOW);
    //     digitalWrite(motor1Pin2, HIGH); 
    //     digitalWrite(motor2Pin1, LOW);
    //     digitalWrite(motor2Pin2, HIGH); 
    //     digitalWrite(motor3Pin1, LOW);
    //     digitalWrite(motor3Pin2, HIGH); 
    //     digitalWrite(motor4Pin1, LOW);
    //     digitalWrite(motor4Pin2, HIGH); 
    //     delay(100);
    // }
    // else if(PS4.RStickY()<=1 && PS4.RStickY()>=-128 && PS4.RStickX()<=82 && PS4.RStickX()>=-105)
    // {
    //     // Move Backward .. 
    //     // Move DC motor backwards at maximum speed
    //     Serial.println("\t Moving Backwards .. ");
    //     digitalWrite(motor1Pin1, HIGH);
    //     digitalWrite(motor1Pin2, LOW); 
    //     digitalWrite(motor2Pin1, HIGH);
    //     digitalWrite(motor2Pin2, LOW);
    //     digitalWrite(motor3Pin1, HIGH);
    //     digitalWrite(motor3Pin2, LOW); 
    //     digitalWrite(motor4Pin1, HIGH);
    //     digitalWrite(motor4Pin2, LOW); 
    //     delay(100);
    // }
    // else if(PS4.RStickY()>=-96 && PS4.RStickY()<=96 && PS4.RStickX()<=-1 && PS4.RStickX()>=-128)
    // {
    //     // Move Left .. 
    //     Serial.println("\t Moving Left ..");
    //     digitalWrite(motor1Pin1, LOW);
    //     digitalWrite(motor1Pin2, HIGH); 
    //     digitalWrite(motor2Pin1, HIGH);
    //     digitalWrite(motor2Pin2, LOW);
    //     digitalWrite(motor3Pin1, LOW);
    //     digitalWrite(motor3Pin2, HIGH); 
    //     digitalWrite(motor4Pin1, HIGH);
    //     digitalWrite(motor4Pin2, LOW); 
    //     delay(100);
    // }
    // else if(PS4.RStickY()>=-115 && PS4.RStickY()<=115 && PS4.RStickX()>=-1 && PS4.RStickX()<=128)
    // {
    //     // Move Right .. 
    //     Serial.println("\t Moving Right ..");
    //     digitalWrite(motor1Pin1, HIGH);
    //     digitalWrite(motor1Pin2, LOW); 
    //     digitalWrite(motor2Pin1, LOW);
    //     digitalWrite(motor2Pin2, HIGH);
    //     digitalWrite(motor3Pin1, HIGH);
    //     digitalWrite(motor3Pin2, LOW); 
    //     digitalWrite(motor4Pin1, LOW);
    //     digitalWrite(motor4Pin2, HIGH); 
    //     delay(100);
    // }
    // else if(PS4.R1())
    // {
    //   Serial.println("\n\t Servo On (Correct) ");
    //   for(int posDegrees = 0; posDegrees <= 360; posDegrees++) 
    //   {
    //     setServos(posDegrees);
    //     delay(20);
    //     Serial.println(posDegrees);
    //   }
    // }
    // else if(PS4.L1())
    // {
    //   Serial.println("\n\t Servo On (Inverse) ");
    //   for(int posDegrees = 360; posDegrees >= 0; posDegrees--) 
    //   {
    //       setServos(posDegrees);

    //       delay(20);
    //       Serial.println(posDegrees);
    //   }
    // }
    // else if(PS4.Circle())
    // {
    //   for(int pos=0;pos<=180;pos++)
    //   {
    //     setServos(pos);
    //     Serail.println(pos);
    //     delay(20);
    //   }
    //   for(int pos=180;pos>=0;pos--)
    //   {
    //     setServos(pos);
    //     Serail.println(pos);
    //     delay(20);
    //   }
    // }
    
  }
  else
  {
      Serial.println("\t Eat 5-Star , Do Nothing ..");
  }
  delay(100);
}
