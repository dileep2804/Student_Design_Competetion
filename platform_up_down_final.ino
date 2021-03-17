#include <Servo.h>
#include <Stepper.h>

Servo myservo1; 
Servo myservo2;

int pos = 0;    
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution

Stepper myStepper(stepsPerRevolution, 8, 11, 10, 9);

void setup() {
//pinMode(inPin, INPUT);
    myservo1.attach(7);  // myside
    myservo2.attach(50);
  // set the speed at 60 rpm:
  myStepper.setSpeed(100);

  Serial.begin(9600);
}

void loop() {
  //fun1();//close
  //delay(2000);
  //platform_up(); 
  
 // val = analogRead(inPin);   // read the input pin
//Serial.println(val);
 // if(val>=800)
  //  digitalWrite(13,HIGH);
  /*fun2(); //open
  delay(2000);
 platform_up(); 
  fun1();
  delay(2000);
  platform_down();
  delay(5000);
  */
/*else

  {  digitalWrite(13,HIGH);}*/
  fun1(); //close
  delay(2000);
  platform_up2(); 
  delay(2000);
  fun2(); //open
  delay(2000);
  platform_up3(); 
  fun1();
  delay(2000);
  platform_down();
  delay(5000);
  delay(100000);


  
//    platform_up();
//   delay(1000);
//   
//   myservo1.write(0);
//   delay(1000);
//   myservo2.write(70);
//   delay(1500);
//   
//   //servo_clip();
//   //delay(1000);
//   myservo1.write(40);
//   delay(1000);
//   myservo2.write(0);
//   delay(1500);
//   
//   platform_down();
//   delay(1000000);
}
void fun1()
{
  
   myservo1.write(90);
   myservo2.write(50);
   delay(1500);
}
void fun2()
{
  
   myservo1.write(20);
   myservo2.write(180);
   delay(1500);
}
void platform_up(){
    // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(7100); //6000
  delay(500);
}

void platform_up2(){
    // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(1900); //6000
  delay(500);
}

void platform_up3(){
    // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(5200); //6000
  delay(500);
}

void platform_down(){
    Serial.println("counterclockwise");                // step one revolution in the other direction:
   myStepper.step(-7100);//-6000
   delay(500);
}



void servo_clip(){
  for (int pos = 40; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   //myservo1.write(0);
   
  for (int pos = 0; pos <= 70; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   //myservo2.write(70);
   delay(3000);
   
  for (int pos = 0; pos <= 40; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
   //myservo1.write(40);
   for (int pos = 70; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
   //myservo2.write(0);
   delay(3000);
   
 }
