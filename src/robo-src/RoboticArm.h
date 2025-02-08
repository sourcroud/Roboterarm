//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_ROBOTICARM_H
#define ROBOTERARM_ROBOTICARM_H

#include "Arduino.h"
#include "JoyStick.h"
#include "LED.h"
#include "mgmDriver.h"
#include "MicroSwitch.h"
#include "TouchSensor.h"
#include "GripperButton.h"
#include "Servo.h"
#include "ServoWrapper.h"

class RoboticArm {
private:
    int lastServoPos;

    friend class GripperButton;
    friend class JoyStick;
    friend class LED;
    friend class mgmDriver;
    friend class MicroSwitch;
    friend class ServoWrapper;
    friend class TouchSensor;
    friend class Servo;
public:
    JoyStick joyStick1;
    JoyStick joyStick2;
    LED ledGreen;
    LED ledYellow;
    LED ledRed;
    mgmDriver mgmDriver1;
    mgmDriver mgmDriver2;
    MicroSwitch microSwitch1;
    MicroSwitch microSwitch2;
    MicroSwitch microSwitch3;
    MicroSwitch microSwitch4;
    TouchSensor touchSensor;
    ServoWrapper gripper;
    Servo servo;
public:
    RoboticArm();
    //Copy-Konstruktor
    RoboticArm(const RoboticArm& other) = default;
    ~RoboticArm();
    void updateSensors();
    void updateActuators();
};


#endif //ROBOTERARM_ROBOTICARM_H
