#include <Stepper.h>
#include <Servo.h>
//#include<cmath.h>
//for stepper1 200steps==3.6cm
//for stepper2 200steps==3.5cm

int one_coor= 30;
int three_coor= 32;
int five_coor= 34;

Servo myservo1;  // create servo object to control a servo
Servo myservo2;
// twelve servo objects can be created on most boards

int pos1 = 0;    // variable to store the servo position
int pos2 = 0;
int xo=200*1.6;
int yo=200*4.4;

float n_r_1[]={4.28,4.28,2.32,0.22,0.22};                // no. of rotation required to reach the coordinate    {5.65,4.00,5.65,4.00,2.33};       
float n_r_2[]={3.50,1.3,2.72,3.50,1.3};                // no. of rotation                                    {7.30,7.400,5.24,4.39,6.29};

const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
//const int s_cm1=56 steps==0.28 rotation;
//const int s_cm2=57 steps==0.285 rotation;

float coor3_1[]={3.65,1.2,1.2};
float coor3_2[]={2.72,3.40,1.3};
float m,n;

// initialize the stepper library on pins 8 through 11:
Stepper myStepper1(stepsPerRevolution,6, 7, 8, 9);
Stepper myStepper2(stepsPerRevolution, 10, 11, 12, 13);

void setup() {
  // set the speed at 60 rpm:
  pinMode(one_coor,INPUT);
  pinMode(three_coor,INPUT);
  pinMode(five_coor,INPUT);
  myStepper1.setSpeed(60);
  myStepper2.setSpeed(60); 
  myservo1.attach(4);  
  myservo2.attach(3);   
  Serial.begin(9600);
}

void loop() {
  centre();
  //three_some();
  // one_coordinate();
   //three_coordinates();
  // five_coordinates();
}

void five_coordinates(){
       for(int x=0;x<5;x++){
        servo_with_paper();
        go_to_xo();
        stepper1_fw(x);
        servo_without_paper();
        bw_one_by_one(x);
        back_to_xo();
   }
}
void go_to_xo()
{
   for(int i=1;i<=xo;i++)
    {
      myStepper1.step(1);
      delay(2);
      //myStepper2.step(1);
      //delay(2);
    }
     for(int i=1;i<=yo;i++)
    {
      //myStepper1.step(1);
      //delay(2);
      myStepper2.step(1);
      delay(2);
    }
}
void back_to_xo()
{
  for(int i=1;i<=yo;i++)
    {
      //myStepper1.step(1);
      //delay(2);
      myStepper2.step(-1);
      delay(2);
    }
   for(int i=1;i<=xo;i++)
    {
      myStepper1.step(-1);
      delay(2);
      //myStepper2.step(1);
      //delay(2);
    }
     
}
void stepper1_fw(int value){
     Serial.println("clockwise");
    m=stepsPerRevolution*n_r_1[value];
    Serial.println("clockwise");
    n=stepsPerRevolution*n_r_2[value];
    
     for(int i=1;i<=n;i++)
   {
      myStepper2.step(1);
      delay(2);
   }
   for(int i=1;i<=m;i++)
   {
      myStepper1.step(1);
      delay(2);
   }
   delay(500);  
    //delay(500);
    /*for(int i=1;i<=min(abs(m),abs(n));i++)
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
    }*/                                                                                                                                                                                                               
}

void stepper_bw(int value){
     Serial.println("anticlockwise");
    m=stepsPerRevolution*n_r_1[value];
    myStepper1.step(-m);
    Serial.println("anticlockwise");
    n=stepsPerRevolution*n_r_2[value];
    myStepper2.step(-n);
  for(int i=1;i<=m;i++)
   {
      myStepper1.step(-1);
      delay(2);
   }
   for(int i=1;i<=n;i++)
   {
      myStepper2.step(-1);
      delay(2);
   }
   
    delay(500);              
}
 /*   myStepper2.step(n);
    delay(500);
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
    }*/

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
  for (pos1=10; pos1<=150; pos1+=1) { // goes from 0 degrees to 180 degrees
    myservo1.write(pos1);
    delay(15);
   // myservo2.write(pos2);                    // tell servo to go to position in variable 'pos'
    //delay(15);                       // waits 15ms for the servo to reach the position
  }
  for(int pos2=150;pos2>=135;pos2--)
  {
     myservo2.write(pos2);
    delay(15);
  }
  delay(1000);
  
}
void bw_one_by_one(int value){
      m=stepsPerRevolution*n_r_1[value];
    myStepper1.step(-m/2); 
    delay(500);
    for (pos2=135; pos2>=0; pos2--){
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



void centre(){
  
  //go_to_xo();
  servo_WithOut_paper();
  myStepper1.step(0.26*200*14); //x= 13+
  delay(500);
  servo_with_paper();    
  myStepper2.step(0.26*200*24); //y = 22+
  delay(500);
  
  /*myStepper1.step(0.26*200*1); //x =1+
  delay(500);
  */
  servo_WithOut_paper();
  
  myStepper2.step(-0.26*200*24); //y = 22- Clip paper
  delay(500);
  myStepper1.step(-0.26*200*14); //x =14-
  delay(3000);
}

void three_some()
{ servo_WithOut_paper();
  
  myStepper1.step(0.26*200*14); //x= 14+
  delay(500);
  servo_with_paper();    
   
  myStepper2.step(0.26*200*22); //y = 22+
  delay(500);
 
  myStepper1.step(-0.26*200*11); //x =10-
  servo_WithOut_paper();
  myStepper1.step(0.26*200*11); //x =10+
  
  myStepper2.step(-0.26*200*22 ); //y = 22- Clip paper
  delay(500);

    
  //lets clip
  servo_with_paper();
  
  myStepper2.step(0.26*200*26); //y = 17+
  delay(500);
 
  myStepper1.step(0.26*200*6); //x =10+
  
  servo_WithOut_paper();

  myStepper1.step(-0.26*200*6 ); //x =10+
  
  myStepper2.step(-0.26*200*26); //y = 17- 
  delay(500);

  //lets clip
  servo_with_paper();
  
  myStepper2.step(0.26*200*16); //y = 17+
  delay(500);
 
  //myStepper1.step(0.26*200*2); //x =10+
  
  servo_WithOut_paper();


  myStepper2.step(-0.26*200*16); //y = 17- 
  delay(500);
  
  myStepper1.step(-0.26*200*16); //x =10+
  delay(1000);
  
}

void five_some()
{
  myStepper1.step(0.26*200*14); //x= 14+
  delay(500);
  servo_with_paper();    
  
  myStepper2.step(0.26*200*24); //y = 22+
  delay(500);
 
  myStepper1.step(-0.26*200*10); //x =10-
  servo_WithOut_paper();
  myStepper1.step(0.26*200*10); //x =10+
  
  myStepper2.step(-0.26*200*24); //y = 22- Clip paper
  delay(500);

    
  //lets clip
  servo_with_paper();
  
  myStepper2.step(0.26*200*30); //y = 17+
  delay(500);
 
  myStepper1.step(0.26*200*10); //x =10+
  
  servo_WithOut_paper();

  myStepper1.step(-0.26*200*10); //x =10+
  
  myStepper2.step(-0.26*200*30); //y = 17- 
  delay(500);

  //lets clip
  servo_with_paper();
  
  myStepper2.step(0.26*200*18); //y = 17+
  delay(500);
 
  myStepper1.step(0.26*200*10); //x =10+
  
  servo_WithOut_paper();

  myStepper1.step(-0.26*200*10); //x =10+
  delay(500);
  
  myStepper2.step(-0.26*200*18); //y = 17- 
  delay(500);
  
  myStepper1.step(-0.26*200*14); //x =10+
  delay(1000);
  
}

void one_coordinate(){
  servo_with_paper();
  go_to_xo();
  myStepper1.step(2.32*200);
  delay(500);
  myStepper2.step(2.72*200);
  delay(500);
  servo_WithOut_paper();
  myStepper1.step(-2.32*200);
  delay(500);
  myStepper2.step(-2.72*200);
  delay(500);
  back_to_xo();
  delay(3000);
}
void servo_WithOut_paper()
  {
  for (pos1=10,pos2=150; pos1<=150 && pos2>=0; pos1+=1,pos2-=1) { // goes from 0 degrees to 180 degrees
    myservo1.write(pos1);
    delay(15);
    myservo2.write(pos2);                    // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  delay(1000);
}

void three_coordinates(){
  for(int i=0;i<3;i++){
  servo_with_paper();
  go_to_xo();
     myStepper1.step(stepsPerRevolution*coor3_1[i]);
     delay(500);
    myStepper2.step(stepsPerRevolution*coor3_2[i]);
    delay(500);
    servo_without_paper();
    bw_onebyone(i);
    back_to_xo();
  }
}
void bw_onebyone(int value){
      m=stepsPerRevolution*coor3_1[value];
    myStepper1.step(-m/2); 
    delay(500);
    for (pos2=135; pos2>=0; pos2--){
      myservo2.write(pos2);
      delay(15);
    }
    Serial.println("anticlockwise");
    n=stepsPerRevolution*coor3_2[value];
    myStepper2.step(-n/2);
    delay(500); 
    
    m=stepsPerRevolution*coor3_1[value];
    myStepper1.step(-m/2); 
    delay(500);
    Serial.println("anticlockwise");
    n=stepsPerRevolution*coor3_2[value];
    myStepper2.step(-n/2);
    delay(500); 
}
