#include <PS4Controller.h>
#include <Servo.h>

static const int servoPin = 13;
Servo servo1;

void setup() {
  Serial.begin(115200);
  PS4.begin("48:89:e7:cd:91:59");
  Serial.println(" Ready .. ");
  servo1.attach(servoPin);
}

void loop() {
  if (PS4.isConnected()) {
    // Serial.println("Connected!");
    // if(PS4.R1())
    // {
    //    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
    //       servo1.write(posDegrees);
    //       // Serial.println(posDegrees);
    //       delay(25);
    //   }
    // }
    // if(PS4.L1())
    // {
    //   for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
    //       servo1.write(posDegrees);
    //       // Serial.println(posDegrees);
    //       delay(25);
    //   }
    // }
    if(PS4.RStickX()<=0 && PS4.RStickX()>=-4 && PS4.RStickY()<=4 && PS4.RStickY()>=-4)
    {
        // No Motion .. 
        Serial.println("\t No Motion ..");
    }
    else if(PS4.RStickY()>=-96 && PS4.RStickY()<=96 && PS4.RStickX()<=-1 && PS4.RStickX()>=-128)
    {
        // Move Left .. 
        Serial.println("\t Moving Left ..");
    }
    else if(PS4.RStickY()>=-115 && PS4.RStickY()<=115 && PS4.RStickX()>=-1 && PS4.RStickX()<=128)
    {
        // Move Right .. 
        Serial.println("\t Moving Right ..");
    }
    else if(PS4.RStickY()>=2 && PS4.RStickY()<=128 && PS4.RStickX()<=81 && PS4.RStickX()>=-105)
    {
        // Move Forward .. 
        Serial.println("\t Moving Forward ..");
    }
    else if(PS4.RStickY()<=2 && PS4.RStickY()>=-128 && PS4.RStickX()<=82 && PS4.RStickX()>=-105)
    {
        // Move Backward .. 
        Serial.println("\t Moving Backward ..");
    }
    else
    {
        Serial.println("\t Eat 5-Star , Don Nothing ..");
    }

  }
  delay(1000);
}

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
