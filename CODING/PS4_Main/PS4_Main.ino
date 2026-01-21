
#include <PS4Controller.h>

#define m1_pwm_pin 12
#define m1_dir_pin 13
#define m2_pwm_pin 27
#define m2_dir_pin 14
// #define m3_pwm_pin 2
// #define m3_dir_pin 4
// #define m4_pwm_pin 32
// #define m4_dir_pin 33

int m1_pwm = 0;
byte m1_dir = 0;
int m2_pwm = 0;
byte m2_dir = 0;
// int m3_pwm = 0;
// byte m3_dir = 0;
// int m4_pwm = 0;
// byte m4_dir = 0;

// char ack = 6;
int x = 0;
int y = 0;
int z = 0;

// long data_rate = 20;
// long prev_time = 0;
// long current_time = 0;

void setup()
{
  Serial.begin(115200);
  //MAC address of your PS4
  PS4.begin("b4:8c:9d:8c:ea:aa");
  // PS4.begin("dc:21:5c:39:af:e3");  
  
  pinMode(m1_pwm_pin, OUTPUT);
  pinMode(m1_dir_pin, OUTPUT);
  pinMode(m2_pwm_pin, OUTPUT);
  pinMode(m2_dir_pin, OUTPUT);
  // pinMode(m3_pwm_pin, OUTPUT);
  // pinMode(m3_dir_pin, OUTPUT);
  // pinMode(m4_pwm_pin, OUTPUT);
  // pinMode(m4_dir_pin, OUTPUT);
  
  delay(1000);
}

void loop()
{
  // current_time = millis();
  // if (current_time - prev_time > data_rate)
  // {
  //   sendValues(); //Send data to Atmega328
  //   //printValues(); //Prints data on serial port of debugging
  //   led = !led;
  //   digitalWrite(led_pin, led);
  //   prev_time = current_time;
  // }

  readValues();       // Get values from PS4
  calculateValues();  // Calculate direction and PWM of each motor
  driveMotors();      // Driver each motor

}

// void readValues()
// {
//   if (Serial.read() == 6)
//   {
//     x = Serial.parseInt();
//     y = Serial.parseInt();
//     z = Serial.parseInt();

//     led = !led;
//     digitalWrite(led_pin, led);
//   }
// }

void calculateValues()
{
  m1_pwm = 2 * (y - x - z);
  m2_pwm = 2 * (x + y - z);
  // m3_pwm = 2 * (x + y + z);
  // m4_pwm = 2 * (y - x + z);

  m1_pwm = constrain(m1_pwm, -255, 255);
  if (m1_pwm > 0)
  {
    m1_dir = 1;
    m1_pwm = 255 - m1_pwm;
  }
  else
  {
    m1_dir = 0;
    m1_pwm = abs(m1_pwm);
  }

  m2_pwm = constrain(m2_pwm, -255, 255);
  if (m2_pwm > 0)
  {
    m2_dir = 0;
  }
  else
  {
    m2_dir = 1;
    m2_pwm = 255 + m2_pwm;
  }

  // m3_pwm = constrain(m3_pwm, -255, 255);
  // if (m3_pwm > 0)
  // {
  //   m3_dir = 0;
  // }
  // else
  // {
  //   m3_dir = 1;
  //   m3_pwm = 255 + m3_pwm;
  // }

  // m4_pwm = constrain(m4_pwm, -255, 255);
  // if (m4_pwm > 0)
  // {
  //   m4_dir = 1;
  //   m4_pwm = 255 - m4_pwm;
  // }
  // else
  // {
  //   m4_dir = 0;
  //   m4_pwm = abs(m4_pwm);
  // }

}

void driveMotors()
{
  digitalWrite(m1_dir_pin, m1_dir);
  analogWrite(m1_pwm_pin, m1_pwm);

  digitalWrite(m2_dir_pin, m2_dir);
  analogWrite(m2_pwm_pin, m2_pwm);

  // digitalWrite(m3_dir_pin, m3_dir);
  // analogWrite(m3_pwm_pin, m3_pwm);

  // digitalWrite(m4_dir_pin, m4_dir);
  // analogWrite(m4_pwm_pin, m4_pwm);
}

void readValues()
{
  x = PS4.LStickX();
  y = PS4.LStickY();
  z = PS4.RStickX(); //rotation
}

// void sendValues()
// {
//   Serial.print(ack);
//   Serial.println(x);
//   Serial.println(y);
//   Serial.println(z);
// }

// void printValues()
// {
//   Serial.print(x);
//   Serial.print("\t");
//   Serial.print(y);
//   Serial.print("\t");
//   Serial.println(z);
// }

