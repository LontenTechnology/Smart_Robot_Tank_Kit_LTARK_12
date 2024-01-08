
#include <Servo.h>

Servo myservo;

void setup(){
  Serial.begin(9600);
  myservo.attach(13);
  // Set initial angle of servo to 90°
  myservo.write(90);
  delay(1000);
}

void loop(){
  // Set angle of servo to 15°
  myservo.write(0);
  delay(2000);
  myservo.write(168);
  delay(2000);
  myservo.write(90);
  delay(2000);

}
