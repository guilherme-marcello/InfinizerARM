#include <InfinizerARM.h>
#define trigger 13
#define echo 12

Robot robot;
Ultrasonic lateral_sensor(trigger, echo);
Motordriver motor((uint8_t[6]){9, 4, 3, 6, 5, 10});

void setup(){
  lateral_sensor.set_side(Ultrasonic::Side::RIGHT);
  robot.set_motordriver(motor);
}

void loop(){
  // avoid obstacle detected by lateral_sensor, keeping a security distance of 5cm and 40/255 'speed'
  robot.avoid(lateral_sensor, 5, 40);
}
