#ifndef InfinizerARM_h
#define InfinizerARM_h
#include "Arduino.h"

class Ultrasonic {
  public:
    Ultrasonic(int Trigger, int Echo);
    int get_distance();
  private:
    int _trigger;
    int _echo;
};
class Robot {
  public:
    Robot();
    bool isObstacleInFront(int distance, int sec_distance=20);
  private:
    bool _robot;
};
class Motordriver {
  public:
    Motordriver(uint8_t pinos[6]);
    void stop();
    void right(int valueSA, int valueSB);
    void left(int valueSA, int valueSB);
    void forward(int valueSA, int valueSB);
    void backwards(int valueSA, int valueSB);
  private:
    int S_A;  //speed motor a
    int M_A1; //motor a = +
    int M_A2; //motor a = -
    int M_B1; //motor b = -
    int M_B2; //motor b = +
    int S_B;  //speed motor    
};
#endif

