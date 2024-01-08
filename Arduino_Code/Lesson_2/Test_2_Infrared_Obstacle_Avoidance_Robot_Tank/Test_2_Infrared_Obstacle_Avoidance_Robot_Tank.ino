#define ENA  5              //pin of controlling speed---- ENA of motor driver board
#define ENB  6              //pin of controlling speed---- ENB of motor driver board
int pinLB=2;              //pin of controlling turning---- IN1 of motor driver board
int pinLF=4;             //pin of controlling turning---- IN2 of motor driver board
int pinRB=7;            //pin of controlling turning---- IN3 of motor driver board
int pinRF=8;            //pin of controlling turning---- IN4 of motor driver board
volatile int left_light;
volatile int right_light;

void setup(){
  Serial.begin(9600);
  left_light = 0;
  right_light = 0;
  pinMode(A3, INPUT);
  pinMode(A2, INPUT);
  pinMode(ENA,OUTPUT);    // pin 5(PWM) 
  pinMode(ENB,OUTPUT);    // pin 6(PWM) 
  pinMode(pinLB,OUTPUT);  // pin 2
  pinMode(pinLF,OUTPUT);  // pin 4
  pinMode(pinRB,OUTPUT);  // pin 7
  pinMode(pinRF,OUTPUT);  // pin 8
}

void loop(){
  left_light = digitalRead(A3);
  right_light = digitalRead(A2);
  Serial.print("left_light_value = ");
  Serial.println(left_light);
  Serial.print("right_light_value = ");
  Serial.println(right_light);
  if (left_light==0&& right_light==0) {
    stopp();
    delay(500);
    back();
    Set_Speed(200);//setting speed 200
    delay(500);
    if (random(1, 10) > 5) 
    {
      turnL();
      Set_Speed(200);
    } 
    else 
    {
      turnR();
      Set_Speed(200);
    }
    delay(500);
  } else if (left_light==0&& right_light==1) {
    back();
    Set_Speed(200);
    delay(500);
    turnR();
    Set_Speed(200);
    delay(500);
  } else if (left_light==1&& right_light==0) {
    back();
    Set_Speed(200);
    delay(500);
    turnL();
    Set_Speed(200);
    delay(500);
  } else {
    advance();
    Set_Speed(200);
  }
}


void Set_Speed(unsigned char pwm) //function of setting speed
{
  analogWrite(ENA,pwm);
  analogWrite(ENB,pwm);
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
