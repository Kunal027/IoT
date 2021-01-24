#define BLYNK_PRINT  Serial;
#include<ESP8266Wifi.h>
#include<BlynkSimpleEsp8266.h>

char auth[] = "afa759a0c53348b7bfbd437d82e24a93";
char ssid[] = "sonu";
char pass[] = "sonu199";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // put your main code here, to run repeatedly:
  Blynk.run();
}
