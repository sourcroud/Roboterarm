//
// Created by sourc on 30.10.2024.
//

#include "RoboticArm.h"
#include "Pinbelegung.h"

RoboticArm::RoboticArm()
: // gripperButton1(gripperButton1Pin), gripperButton2(gripperButton2Pin),
  joyStick1(joyStick1XPin, joyStick1YPin, joyStick1SelPin),
  joyStick2(joyStick2XPin, joyStick2YPin, joyStick2SelPin),
  ledGreen(ledGreenPin),
  ledYellow(ledYellowPin),
  ledRed(ledRedPin),
  mgmDriver1(mgmDriver1IN1Pin, mgmDriver1IN2Pin, mgmDriver1IN3Pin, mgmDriver1IN4Pin, mgmDriver1ENAPin, mgmDriver1ENBPin),
  mgmDriver2(mgmDriver2IN1Pin, mgmDriver2IN2Pin, mgmDriver2IN3Pin, mgmDriver2IN4Pin, mgmDriver2ENAPin, mgmDriver2ENBPin),
  microSwitch1(microSwitch1Pin),
  microSwitch2(microSwitch2Pin),
  microSwitch3(microSwitch3Pin),
  microSwitch4(microSwitch4Pin),
  touchSensor(touchSensorPin),
  servo()
{
    servo.attach(servoMotorPin);
}

RoboticArm::RoboticArm(const RoboticArm &other)
: joyStick1(other.joyStick1),
  joyStick2(other.joyStick2),
  ledGreen(other.ledGreen),
  ledYellow(other.ledYellow),
  ledRed(other.ledRed),
  mgmDriver1(other.mgmDriver1),
  mgmDriver2(other.mgmDriver2),
  microSwitch1(other.microSwitch1),
  microSwitch2(other.microSwitch2),
  microSwitch3(other.microSwitch3),
  microSwitch4(other.microSwitch4),
  touchSensor(other.touchSensor),
  servo(other.servo)
{

}

void RoboticArm::updateSensors() {

}

void RoboticArm::updateActuators() {

}


