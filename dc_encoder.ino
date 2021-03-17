  
/*     Arduino Rotary Encoder Tutorial
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
  #include <Servo.h>
 #define outputA 8
 #define outputB 9

 int dr = 6;
 int pwm = 7; 
 
  int counter = 0; 
 int aState;
 int aLastState;  

  Servo myservo1;  // create servo object to control a servo
  Servo myservo2;
  int pos = 0;  
void setup() { 
      myservo1.attach(2); //rotate // attaches the servo on pin 9 to the servo object
    myservo2.attach(3); //open // attaches the servo on pin 9 to the servo object //0 pe 
   pinMode (outputA,INPUT);
   pinMode (outputB,INPUT);
   pinMode (pwm,OUTPUT);
   pinMode (dr,OUTPUT);
   
   Serial.begin (9600);
   // Reads the initial state of the outputA
   aLastState = digitalRead(outputA); 
 }

 void loop(){
  servo_initial();
  servo2_clip();
    encoder_value();
 }
 void encoder_value()
 {
     aState = digitalRead(outputA); // Reads the "current" state of the outputA
   // If the previous and the current state of the outputA are different, that means a Pulse has occured
   if (aState != aLastState){     
     // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
     if (digitalRead(outputB) != aState) { 
       counter++;
     } 
     Serial.print("Position: ");
     Serial.println(counter);
   } 
   aLastState = aState; // Updates the previous state of the outputA with the current state
   
   if (counter<18){
    forward();
    }
  else if (counter>=18 && counter<100){
    Stop();
    servo1_vert();
    servo2_unclip();
    servo1_horz();
    }
  else if(counter>=100 && counter<=118){
    backward();
    }
  else if (counter>118){
    Stop1();
    }
}
 void forward()
 {
  digitalWrite(dr,HIGH);
  analogWrite(pwm,80);
 }

void Stop(){
  digitalWrite(dr, LOW);
  analogWrite(pwm,0);
  counter=100;
 }
 void backward()
 {
  digitalWrite(dr,LOW);
  analogWrite(pwm,80);
 }
 void Stop1(){
  digitalWrite(dr, LOW);
  analogWrite(pwm,0);
 }

 
void servo_initial(){
    myservo2.write(120); 
    myservo1.write(180);
    delay(3000);
 }
void servo2_clip(){
  myservo2.write(0);
  delay(3000);
}
void servo1_vert(){
  myservo1.write(90);
  delay(3000);
}
void servo2_unclip(){
  myservo2.write(120);
  delay(3000);
}
void servo1_horz(){
  myservo1.write(180);
  delay(3000);
}
