#include <InfinizerARM.h>
Robot robot;
int ok;
int distance = 22;
void setup() {
  return;
}

void loop() {
  if ( !robot.isObstacleInFront(distance) ) { // 22 > 20 is true, so int ok = 1 
    ok = 1;
  }
  else {
    ok = 0;
  }  
}
