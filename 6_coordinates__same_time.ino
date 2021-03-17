#include <Stepper.h>
#include <Servo.h>
//#include<cmath.h>
//for stepper1 200steps==3.6cm
//for stepper2 200steps==3.5cm
Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;
float n_r_1[]={5.65,5.19,4.00,4.00,4.00,2.33};                // no. of rotation required to reach the coordinate
float n_r_2[]={7.30,5.24,7.400,6.29,4.39,6.29};                // no. of rotation
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
//const int s_cm1=56 steps;
//const int s_cm2=57 steps;
// for your motor
float m,n;
//int a,b;
// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution,6, 7, 8, 9);     //dir1-pin9,  dir2-pin7
Stepper myStepper2(stepsPerRevolution, 10, 11, 12, 13);  //dir1-pin13,  dir2-pin11


 
void setup() {
  // set the speed at 60 rpm:
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60); 
  myservo1.attach(4);  
  myservo2.attach(3);   
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
    go_to_coordinates();
}
void go_to_coordinates(){
       for(int x=0;x<6;x++){
        servo_with_paper();
        stepper1_fw(x);
        servo_without_paper();
      // stepper1_bw(x);
       bw_one_by_one(x);
   }
}
void stepper1_fw(int value ){
     Serial.println("clockwise");
    m=stepsPerRevolution*n_r_1[value];
    //myStepper1.step(m/2); 
    Serial.println("clockwise");
    n=stepsPerRevolution*n_r_2[value];
    //myStepper2.step(n);
    //delay(500);
    for(int i=1;i<=min(abs(m),abs(n));i++)
    {
      myStepper1.step(1);
      delay(2);
      myStepper2.step(1);
      delay(2);
    }
    if(abs(m)>abs(n))
    {
      for(int i=1;i<=(abs(m)-abs(n));i++)
      {
         myStepper1.step(1);
      }
    }
    else
    {
      for(int i=1;i<=(abs(n)-abs(m));i++)
      {
         myStepper2.step(1);
      }
    }
   
    delay(500);                                                                                                                                                                                                             
}
void stepper1_bw(int value){
     /*Serial.println("anticlockwise");
    m=stepsPerRevolution*n_r_1[value];
    myStepper1.step(-m/2);
    delay(500);
*/
      Serial.println("anticlockwise");
    m=stepsPerRevolution*n_r_1[value];
    //myStepper1.step(m/2); 
    Serial.println("anticlockwise");
    n=stepsPerRevolution*n_r_2[value];
    //myStepper2.step(n);
    //delay(500);
    for(int i=1;i<=min(abs(m),abs(n));i++)
    {
      myStepper1.step(-1);
      delay(2);
      myStepper2.step(-1);
      delay(2);
    }
    if(abs(m)>abs(n))
    {
      for(int i=1;i<=(abs(m)-abs(n));i++)
      {
         myStepper1.step(-1);
      }
    }
    else
    {
      for(int i=1;i<=(abs(n)-abs(m));i++)
      {
         myStepper2.step(-1);
      }
    }
   
    delay(500);          
}
/*void stepper2_fw(int value){
      Serial.println("clockwise");
    n=stepsPerRevolution*n_r_2[value];
    myStepper2.step(n);
    delay(500);
}*/

/*void stepper2_bw(int value){
      Serial.println("anticlockwise");
     n=stepsPerRevolution*n_r_2[value];
     myStepper2.step(-n);
    delay(500);
}*/
void servo_with_paper()
{
  for (pos1=150,pos2=0; pos1>=10&&pos2<=150; pos1-=1,pos2++) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos1); 
    myservo2.write(pos2);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
}
void servo_without_paper()
{
  for (pos1=10,pos2=150; pos1<=150&&pos2>=0; pos1+=1,pos2--) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos1);
   //myservo2.write(pos2);                    // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
  
}
void bw_one_by_one(int value){
      m=stepsPerRevolution*n_r_1[value];
    myStepper1.step(-m/2); 
    delay(500);
    for (pos2=150; pos2>=0; pos2--){
      myservo2.write(pos2);
      delay(15);
    }
    Serial.println("anticlockwise");
    n=stepsPerRevolution*n_r_2[value];
    myStepper2.step(-n/2);
    delay(500); 
    
    m=stepsPerRevolution*n_r_1[value];
    myStepper1.step(-m/2); 
    delay(500);
    Serial.println("anticlockwise");
    n=stepsPerRevolution*n_r_2[value];
    myStepper2.step(-n/2);
    delay(500); 
}
