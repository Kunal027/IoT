#include <Servo.h>
Servo myservo;
char tag[] ="180088F889E1"; 
char input[12];         
int count = 0;        
boolean flag = 0; 
void setup()  
{
  myservo.attach(9);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);    
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
}
void loop()
{
  digitalWrite(3,1);
  if(Serial.available())
  {
    count = 0;
    while(Serial.available() && count < 12)
    {
      input[count] = Serial.read(); 
      count++; 
      delay(5);
    }
    if(count == 12)
    {
      count = 0;
      flag = 1;
      while(count<12 && flag !=0)  
      {
        if(tag[count]==input[count])
          flag = 1; 
        else
          flag = 0;
      }
      if(flag == 1) 
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
      if(flag == 0)
      {
        for(int k =0; k<= 10; k++)
        {
           digitalWrite(4,HIGH);
        }
      }
    }
  }
}
