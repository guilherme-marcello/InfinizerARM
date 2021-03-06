#ifndef InfinizerARM_h
#define InfinizerARM_h
#include "Arduino.h"

class Ultrasonic {
  public:
    enum Side: byte {
      LEFT,
      RIGHT
    };
    Ultrasonic(uint8_t Trigger, uint8_t Echo);
    uint16_t get_distance();
    Ultrasonic::Side get_side();
    void set_side(Ultrasonic::Side new_side);
  private:
    uint8_t _trigger;
    uint8_t _echo;
    Side    _side;
};

class Motordriver {
  public:
    Motordriver(uint8_t pinos[6]);
    void stop();
    void right(uint8_t valueSA, uint8_t valueSB);
    void left(uint8_t valueSA, uint8_t valueSB);
    void forward(uint8_t valueSA, uint8_t valueSB);
    void backwards(uint8_t valueSA, uint8_t valueSB);
  private:
    uint8_t S_A;  //speed motor a
    uint8_t M_A1; //motor a = +
    uint8_t M_A2; //motor a = -
    uint8_t M_B1; //motor b = -
    uint8_t M_B2; //motor b = +
    uint8_t S_B;  //speed motor    
};

class Robot {
  public:
    Robot();
    bool isObstacleInFront(uint16_t distance, uint16_t sec_distance=20);
    void set_motordriver(Motordriver motordriver);
    void avoid(Ultrasonic ultrasonic, uint16_t sec_distance, uint8_t base_speed);
  private:
    bool _robot;
    Motordriver _motordriver = Motordriver((uint8_t[6]) {});
};

#endif
