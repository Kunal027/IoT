const int led=13;
const int ldr=A0;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(ldr,INPUT);
}

void loop() {
 int ldrstatus=analogRead(ldr);
 if(ldrstatus<50)
 {
  digitalWrite(led,HIGH);
  delay(1000);
  digitalWrite(led,LOW);
 }
 else
 {
  digitalWrite(led,LOW);
 }
}
