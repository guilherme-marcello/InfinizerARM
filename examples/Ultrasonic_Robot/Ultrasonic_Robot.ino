#include <InfinizerARM.h>
#define trigger1 13
#define echo1 12
uint16_t distance;
uint8_t sec_distance = 5; // 5cm

Robot robot;
Ultrasonic frontal(trigger1,echo1);

void setup(){
  return;
}

void loop(){
  distance=frontal.get_distance();
  if (robot.isObstacleInFront(distance)){
    stop_motors();
    delay(7000);
    obstacle_avoidance();
  }
  else {
    line_follower();
  }
}

void stop_motors(){
  return;
}
void line_follower(){
  return;
}
void obstacle_avoidance(){
  return;
}

