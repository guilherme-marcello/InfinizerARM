
# Motor driver and US-sensor integration for Arduino
Version: 1.3.1

Release date: 2022 June 9

Author: Guilherme Marcello (<guilemosmarcello@gmail.com>)

## Summary
This is a library for the Arduino IDE that allows you to control ultrasonic modules in pulse mode (examples: SRF-06, HC-SR04, US-100 et cetera.) and to integrate motor drivers (needs to be able to independently control the speed and rotation of 2 DC motors).

## Supported platforms
This library should work starting with version 1.8.0 (not tested with older versions) and should work on any Arduino board.
## Installation

Download the zip file from main branch, navigate to *Sketch* > *Include Library* > *Add .ZIP Library* and upload it or install from library manager.

Official guideline: https://www.arduino.cc/en/Guide/Libraries

## Documentation
* `public enum Ultrasonic::Side`<br>
  Enumeration of sides where the sensor can be in the robot.
  * `Ultrasonic::Side::LEFT`
  * `Ultrasonic::Side::RIGHT`

* `Ultrasonic(uint8_t Trigger, uint8_t Echo)`<br>
  Constructor. Use trigger and echo pin numbers as `Trigger` and `Echo` arguments. The default sensor side is LEFT.
  * `uint16_t Ultrasonic::get_distance()`<br>
  It sends an ultrasonic pulse (1 per 10 microseconds) and return relative distance in centimeters by calculating the time travel and the speed of the sound (air).
  * `Ultrasonic::Side Ultrasonic::get_side()`<br>
  Returns the sensor side (as public enumerated value).
  * `void Ultrasonic::set_side(Ultrasonic::Side new_side)`<br>
  Updates the sensor side with the value passed as `new_side` argument.
  
* `Motordriver(uint8_t pinos[6])`<br>
  Constructor. Initializes and configures the motor driver using an 6-sized `uiint8_t`  array. The indexed collection argument `pinos` should follow the rule: {ENA,IN1,IN2,IN3,IN4,ENB}. 
  
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
  
 * `Robot()`<br>
  Constructor. There is no motordriver set by default.
    
  * `bool Robot::isObstacleInFront(int distance, int sec_distance=20)`<br>
  Returns true if argument `distance`is less or equal than optional argument `sec_distance` else returns false.
  
  * `void Robot::set_motordriver(Motordriver motordriver)`<br>
  Updates the current motordriver with the value passed as `motordriver` argument.
  
  * `void Robot::avoid(Ultrasonic ultrasonic, uint16_t sec_distance, uint8_t base_speed)`<br>
  Using `ultrasonic` instance, checks whether the distance from the sensor to the nearest object is less than `sec_distance`(cm) and adjusts the speed of the motors accordingly. The applied 'speeds' only take on the values `base_speed` and `base_speed/2`. Requires a set motordriver (see method `Robot::set_motordriver`).
  
## Feedback
If you have any feedback, please reach out to me at guilemosmarcello@gmail.com

## License
MIT
