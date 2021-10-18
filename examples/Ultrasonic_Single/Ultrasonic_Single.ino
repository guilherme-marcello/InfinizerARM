#include <InfinizerARM.h>
#define trigger 13
#define echo 12
uint16_t distancia;
Ultrasonic sensorUltra(trigger,echo);
void setup(){
  Serial.begin(9600);
}
void loop(){
  distancia = sensorUltra.get_distance();
  Serial.print(distancia);
  Serial.println(" cm");
}
