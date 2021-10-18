
# Motor driver and US-sensor integration for Arduino
Version: 1.2.1

Release date: 2021 October 18

Author: Guilherme Marcello (<guilemosmarcello@gmail.com>)

## Summary
This is a library for the Arduino IDE that allows you to control ultrasonic modules in pulse mode (examples: SRF-06, HC-SR04, US-100 et cetera.) and to integrate motor drivers (needs to be able to independently control the speed and rotation of 2 DC motors).

## Supported platforms
This library should work starting with version 1.8.0 (not tested with older versions) and should work on any Arduino board.
## Installation

Download the zip file from main branch, navigate to *Sketch* > *Include Library* > *Add .ZIP Library* and upload it or install from library manager.

Official guideline: https://www.arduino.cc/en/Guide/Libraries

## Documentation
* `Ultrasonic(uint8_t Trigger, uint8_t Echo)`<br>
  Constructor. Use trigger and echo pin numbers as `Trigger` and `Echo` arguments.
  
  * `uint16_t Ultrasonic::get_distance()`<br>
  It sends an ultrasonic pulse (1 per 10 microseconds) and return relative distance in centimeters by calculating the time travel and the speed of the sound (air).

* `Robot()`<br>
  Constructor.
  
  * `bool Robot::isObstacleInFront(int distance, int sec_distance=20)`<br>
  Returns true if argument `distance`is less or equal than optional argument `sec_distance` else returns false.
  
* `Motordriver(uint8_t pinos[6])`<br>
  Constructor. Iniitializes and configures the motor driver using an 6-sized `uiint8_t`  array. The indexed collection argument `pinos` should follow the rule: {ENA,IN1,IN2,IN3,IN4,ENB}. 
  
  * `void Motordriver::stop()`<br>
  Writes LOW to both motors enable pin.
  
  * `void Motordriver::right(uint8_t valueSA, uint8_t valueSB)`<br>
  Writes analog values `valueSA` and `valueSB` to motor driver pins. Motor rotation: A-Clockwise, B-Counterclockwise. 
  
  * `void Motordriver::left(uint8_t valueSA, uint8_t valueSB)`<br>
  Writes analog values `valueSA` and `valueSB` to motor driver pins. Motor rotation: A-Counterclockwise, B-Clockwise. 

  * `void Motordriver::forward(uint8_t valueSA, uint8_t valueSB)`<br>
  Writes analog values `valueSA` and `valueSB` to motor driver pins. Motor rotation: A-Clockwise, B-Clockwise. 

  * `void Motordriver::backwards(uint8_t valueSA, uint8_t valueSB)`<br>
  Writes analog values `valueSA` and `valueSB` to motor driver pins. Motor rotation: A-Counterclockwise, B-Counterclockwise. 
