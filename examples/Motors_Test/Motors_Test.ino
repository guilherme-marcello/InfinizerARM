#include <InfinizerARM.h>

// Motordriver pins order:
// EN_A, M_A1, M_A2, M_B1, M_B2, EN_B
Motordriver motor((uint8_t[6]){9, 4, 3, 6, 5, 10});

void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.println("Smooth FORWARD: increase");
  for(int i=0; i<255; i++){
    motor.forward(i,i);
    delay(50);
  }
  Serial.println("Smooth FORWARD: decrease");
  for(int i=255; i>0; i--){
    motor.forward(i,i);
    delay(50);
  }

  motor.stop();
  Serial.println("STOP");
  delay(1000);  

  motor.left(255,255);
  Serial.println("LEFT 255 255");
  delay(1000);

  motor.right(255,255);
  Serial.println("RIGHT 255 255");
  delay(1000);
}