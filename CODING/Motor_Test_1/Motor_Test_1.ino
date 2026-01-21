
#define MotorDirection=8;
#define MotorSpeed=9;

int speedval=0;

void setup()
{
  Serial.begin(115200);
  pinMode(MotorSpeed, OUTPUT);
  pinMode(MotorDirection, OUTPUT);
}

void loop()
{
  digitalWrite(MotorDirection, LOW);
  for(speedval=0;speedval<255;speddval++)
  {
    analogWrite(MotorSpeed, speedval);
    delay(40);
  }
  analogWrite(MotorSpeed, 0);

  digitalWrite(MotorDirection, HIGH);
  for(speedval=0;speedval<255;speddval++)
  {
    analogWrite(MotorSpeed, speedval);
    delay(40);
  }
  analogWrite(MotorSpeed, 0);
  
}
