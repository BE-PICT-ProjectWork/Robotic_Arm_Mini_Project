
//Locomotion pins
#define loco_dir1_pin 19
#define loco_pwm1_pin 18  
#define loco_dir2_pin 4
#define loco_pwm2_pin 2
#define loco_dir3_pin 13
#define loco_pwm3_pin 12
#define loco_dir4_pin 14
#define loco_pwm4_pin 27


//locomotion
int M1_pwm = 0;
byte M1_dir = 0;
int M2_pwm = 0;
byte M2_dir = 0;
int M3_pwm = 0;
byte M3_dir = 0;
int M4_pwm = 0;
byte M4_dir = 0;
int toggle_mode = 0;

//PS4
float Right_X = 0;
float Right_Y = 0;
float Left_X = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  //locomotion setup
  ledcSetup(0, 8000, 8);
  ledcSetup(1, 8000, 8);
  ledcSetup(2, 8000, 8);
  ledcSetup(3, 8000, 8);

  ledcAttachPin(loco_pwm1_pin, 0);
  ledcAttachPin(loco_pwm2_pin, 1);
  ledcAttachPin(loco_pwm3_pin, 2);
  ledcAttachPin(loco_pwm4_pin, 3);

  pinMode(loco_dir1_pin, OUTPUT);
  pinMode(loco_dir2_pin, OUTPUT);
  pinMode(loco_dir3_pin, OUTPUT);
  pinMode(loco_dir4_pin, OUTPUT);

}

void loop() {

  if (Serial.available() >= sizeof(float) * 3) {
    
    float received_values[3];
    Serial.readBytes((char *)received_values, sizeof(float) * 3);

    // Print the received values
    
    Right_Y = received_values[0];
    Right_X = received_values[1];
    Left_X = received_values[2];   
    
    calculate();
    drive();
  } 
  else {
    //locomotion
    M1_pwm = 0;
    M2_pwm = 0;
    M3_pwm = 0;
    M4_pwm = 0; 
  }
}



void calculate() {
  //locomotion
   // mapped left_y joystick for translation and right_x for rotation - linear mapping
  //both sticks can be used simultaneously
  M1_pwm = (Right_Y - Right_X + Left_X);
  M2_pwm = (Right_Y + Right_X - Left_X);
  M3_pwm = (Right_Y + Right_X + Left_X);
  M4_pwm = (Right_Y - Right_X - Left_X);



  //direction deduction from mapped pwm values
  //dir = 0 bot moves forward
  if (M1_pwm > 0) {
    M1_dir = 0;
  } else {
    M1_dir = 1;
    M1_pwm = abs(M1_pwm);
  }

  if (M2_pwm > 0) {
    M2_dir = 0;
  } else {
    M2_dir = 1;
    M2_pwm = abs(M2_pwm);
  }

  if (M3_pwm > 0) {
    M3_dir = 0;
  } else {
    M3_dir = 1;
    M3_pwm = abs(M3_pwm);
  }

  if (M4_pwm > 0) {
    M4_dir = 0;
  } else {
    M4_dir = 1;
    M4_pwm = abs(M4_pwm);
  }
  
  M1_pwm = constrain(M1_pwm, 0, 255);
  M2_pwm = constrain(M2_pwm, 0, 255);
  M3_pwm = constrain(M3_pwm, 0, 255);
  M4_pwm = constrain(M4_pwm, 0, 255);
   
}


void drive() {
  //locomotion
   //at dir = 0 bot moves forward
  digitalWrite(loco_dir1_pin, M1_dir);
  ledcWrite(0, M1_pwm);

  digitalWrite(loco_dir2_pin, M2_dir);
  ledcWrite(1, M2_pwm);

  digitalWrite(loco_dir3_pin, M3_dir);
  ledcWrite(2, M3_pwm);

  digitalWrite(loco_dir4_pin, M4_dir);
  ledcWrite(3, M4_pwm);

  Serial.print(M1_pwm) ;
  Serial.print("\t") ;
  Serial.print(M1_dir) ;
  Serial.print("\t") ;
  Serial.print(M2_pwm) ;
  Serial.print("\t") ;
  Serial.print(M2_dir) ;
  Serial.print("\t") ;
  Serial.print(M3_pwm) ;
  Serial.print("\t") ;
  Serial.print(M3_dir) ;
  Serial.print("\t") ;
  Serial.print(M4_pwm) ;
  Serial.print("\t") ;
  Serial.print(M4_dir) ;
  Serial.println("\t") ;
}
