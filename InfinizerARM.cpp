#include "Arduino.h"
#include "InfinizerARM.h"
Ultrasonic::Ultrasonic(uint8_t Trigger, uint8_t Echo){
  pinMode(Trigger,OUTPUT);
  pinMode(Echo,INPUT);
  _trigger = Trigger;
  _echo = Echo;
}
uint16_t Ultrasonic::get_distance(){
  digitalWrite(_trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(_trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(_trigger,LOW);
  long dt = pulseIn(_echo,HIGH);
  return dt*0.034*0.5;
}
Robot::Robot(){
  _robot = true;
}
bool Robot::isObstacleInFront(uint16_t distance, uint16_t sec_distance=20){
  return (distance <= sec_distance) ? true : false;
}

Motordriver::Motordriver(uint8_t pinos[6]){
  S_A = pinos[0];  //speed motor a
  M_A1 = pinos[1]; //motor a = +
  M_A2 = pinos[2]; //motor a = -
  M_B1 = pinos[3]; //motor b = +
  M_B2 = pinos[4]; //motor b = -
  S_B = pinos[5];  //speed motor b
  pinMode(M_B1, OUTPUT);
  pinMode(M_B2, OUTPUT);
  pinMode(M_A1, OUTPUT);
  pinMode(M_A2, OUTPUT);
  pinMode(S_B, OUTPUT);
  pinMode(S_A, OUTPUT);
}

void Motordriver::stop(){
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, LOW);
  analogWrite(S_A, 0);
  analogWrite(S_B, 0);
}

void Motordriver::right(uint8_t valueSA, uint8_t valueSB){
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);
  analogWrite(S_A, valueSA);
  analogWrite(S_B, valueSB);
}

void Motordriver::left(uint8_t valueSA, uint8_t valueSB){
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
  analogWrite(S_A, valueSA);
  analogWrite(S_B, valueSB);
}

void Motordriver::forward(uint8_t valueSA, uint8_t valueSB){
  digitalWrite(M_A1, HIGH);
  digitalWrite(M_A2, LOW);
  digitalWrite(M_B1, HIGH);
  digitalWrite(M_B2, LOW);
  analogWrite(S_A, valueSA);
  analogWrite(S_B, valueSB);
}

void Motordriver::backwards(uint8_t valueSA, uint8_t valueSB){
  digitalWrite(M_A1, LOW);
  digitalWrite(M_A2, HIGH);
  digitalWrite(M_B1, LOW);
  digitalWrite(M_B2, HIGH);
  analogWrite(S_A, valueSA);
  analogWrite(S_B, valueSB);
}

