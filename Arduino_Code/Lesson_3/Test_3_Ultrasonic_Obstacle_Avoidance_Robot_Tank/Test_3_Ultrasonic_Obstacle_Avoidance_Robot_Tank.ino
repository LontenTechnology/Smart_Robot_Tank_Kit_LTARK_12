
#include <Servo.h>
#define ENA  5              //pin of controlling speed---- ENA of motor driver board
#define ENB  6              //pin of controlling speed---- ENB of motor driver board
int pinLB=2;              //pin of controlling turning---- IN1 of motor driver board
int pinLF=4;             //pin of controlling turning---- IN2 of motor driver board
int pinRB=7;            //pin of controlling turning---- IN3 of motor driver board
int pinRF=8;            //pin of controlling turning---- IN4 of motor driver board
int mySpeed=200;
Servo myservo;
volatile int Front_Distance;
volatile int Left_Distance;
volatile int Right_Distance;

void Ultrasonic_obstacle_avoidance() {
  Front_Distance=checkdistance();
  if (Front_Distance < 20) {
    stopp();
    delay(1000);
    Detect_Left_and_Right__distance();
    if (Left_Distance < 50 || Right_Distance < 50) {
      if (Left_Distance > Right_Distance) {
        myservo.write(90);
        turnLeft();
        Set_Speed(mySpeed);
        delay(500);
        advance();
        Set_Speed(mySpeed);
      } else {
        myservo.write(90);
        turnRight();
        Set_Speed(mySpeed);
        delay(500);
        advance();
        Set_Speed(mySpeed);
      }   
    }else {
      if (random(1, 10) > 5) {
        myservo.write(90);
        turnLeft();
        Set_Speed(mySpeed);
        delay(500);
        advance();
        Set_Speed(mySpeed);
      } else {
        myservo.write(90);
        turnRight();
        Set_Speed(mySpeed);
        delay(500);
        advance();
	      Set_Speed(mySpeed);
      }
    }
}
else {
      advance();
      Set_Speed(mySpeed);
     }
}


float checkdistance() {
  digitalWrite(10, LOW);
  delayMicroseconds(2);
  digitalWrite(10, HIGH);
  delayMicroseconds(10);
  digitalWrite(10, LOW);
  float distance = pulseIn(11, HIGH) / 58.00;
  delay(10);
  return distance;
}

void Detect_Left_and_Right__distance() {
  myservo.write(165);
  delay(500);
  //Serial.println(Left_Distance);
  delay(100);
  Left_Distance = checkdistance();
  myservo.write(15);
  delay(500);
  //Serial.println(Right_Distance);
  delay(100);
  Right_Distance = checkdistance();
  myservo.write(90);
}

void setup(){
  pinMode(ENA,OUTPUT);    // pin 5(PWM) 
  pinMode(ENB,OUTPUT);    // pin 6(PWM) 
  pinMode(pinLB,OUTPUT);  // pin 2
  pinMode(pinLF,OUTPUT);  // pin 4
  pinMode(pinRB,OUTPUT);  // pin 7
  pinMode(pinRF,OUTPUT);  // pin 8
  myservo.attach(13);
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(11, INPUT);
  
  Front_Distance = 0;
  Left_Distance = 0;
  Right_Distance = 0;
  myservo.write(90);

}

void loop(){
  Ultrasonic_obstacle_avoidance();
}
void Set_Speed(int speedPWM) //function of setting speed
{
  analogWrite(ENA,speedPWM);
  analogWrite(ENB,speedPWM);
}
void advance()    //  going forward
{
     digitalWrite(pinRB,HIGH);   
     digitalWrite(pinRF,LOW);
     digitalWrite(pinLB,HIGH);  
     digitalWrite(pinLF,LOW);
}
void back()         //back up
{
     digitalWrite(pinRB,LOW);  
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,LOW);  
     digitalWrite(pinLF,HIGH); 
}
void turnLeft()      //turn left
  {
     digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,LOW );   
     digitalWrite(pinLB,LOW);   
     digitalWrite(pinLF,LOW);
  }
void turnRight()     //turn right
  {
     digitalWrite(pinRB,LOW);  
     digitalWrite(pinRF,LOW);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,LOW);  
  }
void turnR()         //turn right in place
 {
     digitalWrite(pinRB,LOW);  
     digitalWrite(pinRF,HIGH);
     digitalWrite(pinLB,HIGH);
     digitalWrite(pinLF,LOW); 
 }
void turnL()        //turn left in place
 {
     digitalWrite(pinRB,HIGH);
     digitalWrite(pinRF,LOW );   
     digitalWrite(pinLB,LOW);   
     digitalWrite(pinLF,HIGH);
 }    
void stopp()        //stop
 {
     digitalWrite(pinRB,LOW);
     digitalWrite(pinRF,LOW);
     digitalWrite(pinLB,LOW);
     digitalWrite(pinLF,LOW);
 }
