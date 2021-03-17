#include <Stepper.h>
//for stepper1 200steps==3.6cm
//for stepper2 200steps==3.5cm

float n_r_1[]={-2.77, -1.67, 0, -1.95};                // no. of rotation required to reach the coordinate
float n_r_2[]={-6.29, 0, 1.8, -0.71};                // no. of rotation
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
//const int s_cm1=56;
//const int s_cm2=57;
// for your motor
float m,n;
//int a,b;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution,6, 7, 8, 9);
Stepper myStepper2(stepsPerRevolution, 10, 11, 12, 13);


 
void setup() {
  // set the speed at 60 rpm:
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
    go_to_coordinates();
}
void go_to_coordinates(){
       for(int x=0;x<4;x++){
  // step one revolution  in one direction:
  Serial.println("clockwise");
  m=stepsPerRevolution*n_r_1[x];
  myStepper1.step(m);
  delay(500);
  // step one revolution  in one direction:
  n=stepsPerRevolution*n_r_2[x];
  Serial.println("clockwise");
  myStepper2.step(n);
  delay(500);
  
   delay(2000);
  
  //Serial.println("clockwise");
  m=stepsPerRevolution*n_r_1[x];
  myStepper1.step(-m);
  delay(500);
  // step one revolution  in one direction:
  n=stepsPerRevolution*n_r_2[x];
  //Serial.println("clockwise");
  myStepper2.step(-n);
  delay(500);
   }
   delay(2000);
  }
