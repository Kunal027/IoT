void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
   pinMode(11, OUTPUT);
    pinMode(10, OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, true);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(12, false);    // turn the LED off by making the voltage LOW
  digitalWrite(10, false);
  digitalWrite(11, false);
  delay(500);    // wait for a second
  digitalWrite(12, true);
  delay(500);
  digitalWrite(13, false);
  digitalWrite(11, false);
  digitalWrite(10, false);
  delay(500);
  digitalWrite(11, true);
  delay(500);
  digitalWrite(13, false);
  digitalWrite(12, false);
  digitalWrite(10, false);
  delay(500);
 digitalWrite(10, true);
  delay(500);
  digitalWrite(13,false);
  digitalWrite(11, false);
  digitalWrite(12, false);
  delay(500);
}
