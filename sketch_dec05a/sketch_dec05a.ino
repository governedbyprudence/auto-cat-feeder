#include<Servo.h>
String data;
Servo motor;
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
  Serial.begin(115200);
  motor.attach(5);
  motor.write(0);
}

void loop() {
  
  while(Serial.available()){
  data=Serial.readStringUntil('\n');
  Serial.println(data);
  }
  motor.write(data.toInt());
  delay(1000);
  }
