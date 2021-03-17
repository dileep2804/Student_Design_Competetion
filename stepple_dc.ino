 int pwm = 9;
int in_1= 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(pwm, OUTPUT);
  pinMode(in_1, OUTPUT);

}

void loop() {
    //
    mv_cw();
    //delay(2000);
    Stop1();
    mv_cw1();
    // put your main code here, to run repeatedly:
    //mv_cww();
    Stop();
 }
 void mv_cw(){
   digitalWrite(in_1,HIGH) ;  //clockwise
   analogWrite(pwm,255) ;
   delay(663) ; 
 }
 void mv_cw1(){
   digitalWrite(in_1,HIGH) ;  //clockwise
   analogWrite(pwm,255) ;
   delay(663) ; 
 }
void mv_cww(){
  digitalWrite(in_1,LOW);   //counterclockwise
  analogWrite(pwm,255);      
  delay(2000);
}
void Stop1(){
   digitalWrite(in_1,HIGH) ;
   analogWrite(pwm,0) ;
   delay(1000) ;
}
void Stop(){
   digitalWrite(in_1,HIGH) ;
   analogWrite(pwm,0) ;
   delay(3000) ;
}
