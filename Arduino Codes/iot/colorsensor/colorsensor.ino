const int s0 = 10;
const int s1 = 11;
const int s2 = 12;
const int s3 = 13;
const int out = 8;

int redLed = 7;
int greenLed = 6;
int blueLed = 5;

int red = 4;
int green = 4;
int blue = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  color();

  Serial.print("R Intensity: ");
  Serial.print(red, DEC);
  Serial.print("G Intensity: ");
  Serial.print(green, DEC);
  Serial.print("B Intensity: ");
  Serial.print(blue, DEC);

  if(red < blue && red < green && red <20){
    Serial.println("- (RED Color)");

    digitalWrite(redLed, HIGH);
    digitalWrite(greenLed, LOW);
  }
  else if(blue < red && blue < red){
    Serial.println("- (BLUE Color)");

    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    digitalWrite(blueLed, LOW);
  }
  else{
    Serial.println();
  }
  delay(300);

  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(blueLed, LOW);
}

void color(){
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  digitalWrite(s3, HIGH);

  blue = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  digitalWrite(s2, HIGH);
  
  green = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);

  
}
