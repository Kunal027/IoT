const int trigPin = 9;
const int echoPin = 8;

long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  
  delay(200);

  digitalWrite(trigPin,HIGH);
  
  delay(200);
  
  digitalWrite(trigPin,LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;
  
  if(distance <= 18){
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(100);
  }
  else{
    digitalWrite(LED_BUILTIN, LOW);
  }
  
  Serial.print("Distance: ");
  Serial.println(distance);
    
}
             
