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
#include "ServoMotor.h"
#include "TouchSensor.h"
#include "GripperButton.h"

class RoboticArm {
    friend class GripperButton;
    friend class JoyStick;
    friend class LED;
    friend class mgmDriver;
    friend class MicroSwitch;
    friend class ServoMotor;
    friend class TouchSensor;
private:

public:
    GripperButton gripperButton1; // OPEN
    GripperButton gripperButton2; // CLOSE
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
    ServoMotor servoMotor;
    TouchSensor touchSensor;

public:
    RoboticArm();
    void updateSensors();
    void updateActuators();
};


#endif //ROBOTERARM_ROBOTICARM_H
