#include<Servo.h>
String data;
Servo left,right;
int left_pin = 5;//D1
int right_pin = 12;//D6


void setup() {
  Serial.begin(115200);
  left.attach(left_pin);
  right.attach(right_pin);
  left.write(0);
  right.write(0);

}

void loop() {
    int i;
    for(i=0;i<=180;i++){
      left.write(i);
      right.write(i);
      delay(30);
    }
    for(i=180;i>=0;i--){
      left.write(i);
      right.write(i);
      delay(30);
    }
delay(15);
}
