//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_ROBOTICARM_H
#define ROBOTERARM_ROBOTICARM_H

#include "Arduino.h"
#include "LED.h"
#include "mgmDriver.h"
#include "MicroSwitch.h"
#include "ServoWrapper.h"
#include "Servo.h"
#include "PS2X_lib.h"

class RoboticArm {
private:
    int lastServoPos;
    int error;

    //friend class JoyStick;
    friend class LED;
    friend class mgmDriver;
    friend class MicroSwitch;
    friend class ServoWrapper;
    friend class TouchSensor;
    friend class Servo;
    friend class PS2X;
public:
    //JoyStick joyStick1;
    //JoyStick joyStick2;
    LED ledGreen;
    LED ledYellow;
    LED ledRed;
    mgmDriver mgmDriver1;
    mgmDriver mgmDriver2;
    MicroSwitch microSwitch1;
    MicroSwitch microSwitch2;
    MicroSwitch microSwitch3;
    MicroSwitch microSwitch4;
    ServoWrapper gripper;
    Servo servo;
    PS2X ps2x;
public:
    RoboticArm();
    //Copy-Konstruktor
    RoboticArm(const RoboticArm& other) = default;
    ~RoboticArm();
    void updateSensors();
    void initPS2Controller(int clock, int command, int attention, int data, bool pressures, bool rumble);
    void updateActuators();
};


#endif //ROBOTERARM_ROBOTICARM_H
