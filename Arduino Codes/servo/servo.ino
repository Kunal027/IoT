#include <Servo.h>
Servo myservo;
void setup(){
  myservo.attach(9);
}
void loop()
{
  myservo.write(0);
  delay(500);
  myservo.write(20);
  delay(500);
  myservo.write(40);
  delay(500);
  myservo.write(60);
  delay(500);
  myservo.write(80);
  delay(500);
  myservo.write(90);
  delay(500);
} 
