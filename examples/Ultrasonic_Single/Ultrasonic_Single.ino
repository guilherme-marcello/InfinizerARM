#include <InfinizerARM.h>
int trigger = 13;
int echo = 12;
long distancia;
Ultrasonic sensorUltra(trigger,echo);
void setup(){
  Serial.begin(9600);
}
void loop(){
  distancia = sensorUltra.get_distance();
  Serial.print(distancia);
  Serial.println(" cm");
}
