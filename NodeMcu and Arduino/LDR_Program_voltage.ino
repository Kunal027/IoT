void setup()
{
  Serial.begin(9600);
  pinMode(D0,OUTPUT);
}
void loop()
{
  int value=analogRead(A0);
  float volt=value*(5.0/1023.0);
  Serial.println(volt);
  if(volt<0.10)
  digitalWrite(D0,HIGH);
  else
  digitalWrite(D0,LOW);
}
