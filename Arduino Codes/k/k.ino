#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>
#include <SimpleTimer.h>
#include <DHT.h>
Servo fservo;
Servo gservo;
char auth[] = "4d45fa2a6fe14bfd83ca3ea1d2be4e31";
char ssid[] = "sonu";
char pass[] = "sonu1999";
/*dht 11 begins from here*/
#define DHTPIN 16          // Digital pin 4
#define DHTTYPE DHT11 

#define TRIGGERPIN D5
#define ECHOPIN    D6
  
DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Blynk.virtualWrite(V5, h);  
  Blynk.virtualWrite(V6, t); 
}

void setup()
{
  Serial.begin(9600);
  pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
Blynk.begin(auth, ssid, pass);
dht.begin();
 timer.setInterval(1000L, sendSensor);
  fservo.attach(7);
  gservo.attach(5);  
}

void loop()
{/*ultrasonic*/
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;
  Serial.print(distance);
  Blynk.virtualWrite(V3,distance);

  delay(3500);

  /*ultrasonic*/
  Blynk.run();
  timer.run(); 
}
BLYNK_WRITE(V1)
{
  
gservo.write(param.asInt());
  
}
 BLYNK_READ(V5)
 {
  fservo.write(0);
 }
 

