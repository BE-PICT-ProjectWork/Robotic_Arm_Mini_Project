#include <PS4Controller.h>
#include <Servo.h>

static const int servosPins[3] = {18, 19, 21};
Servo servos[3];

void setServos(int degrees) 
{
    for(int i = 0; i < 3; ++i) 
    {
        servos[i].write((degrees + (35 * i)) % 180);
    }
}

void setup() 
{
    Serial.begin(115200);
    PS4.begin("48:89:e7:cd:91:59");
    Serial.println("\t Ready .. ");
    
    for(int i = 0; i < 3; ++i) 
    {
        if(! (servos[i].attach(servosPins[i]))) 
        {
            Serial.print("\n\t Servo ");
            Serial.print(i);
            Serial.print(" attach error .. ");
        }
    }
}

void loop() 
{
    if (PS4.isConnected()) 
    {
      Serial.println("\t Connected !! ");
      if(PS4.Circle())
      {
        for(int posDegrees = 0; posDegrees <= 180; posDegrees++) 
        {
            setServos(posDegrees);
            // Serial.println(posDegrees);
            delay(20);
        }
        for(int posDegrees = 180; posDegrees >= 0; posDegrees--) 
        {
            setServos(posDegrees);
            // Serial.println(posDegrees);
            delay(20);
        }
      }
    }  
  
    delay(100);
}
