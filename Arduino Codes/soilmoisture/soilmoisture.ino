int sensor_pin = A0;

int output_value = 5 ;

void setup() {
  pinMode(13, OUTPUT);

   Serial.begin(9600);
   

   Serial.println("Reading From the Sensor ...");

   delay(2000);

   }

void loop() {

   output_value= analogRead(sensor_pin);

   output_value = map(output_value,550,0,0,100);

   Serial.print("Mositure : ");

   Serial.print(output_value);

   Serial.println("%");

   delay(1000);
 if(output_value<25)
 {
  digitalWrite(13,HIGH);
  Serial.println("Pump is on");
 }
 if(output_value>25){
  digitalWrite(13,LOW);
  Serial.print("Pump off/n");}
   }
/*int led_pin =13;

int sensor_pin =8;

void setup() {

  pinMode(led_pin, OUTPUT);

  pinMode(sensor_pin, INPUT);

}

void loop() {

  if(digitalRead(sensor_pin) == HIGH){

    digitalWrite(led_pin, HIGH);

  } else {

    digitalWrite(led_pin, LOW);

    delay(1000);

  }

}
*/
