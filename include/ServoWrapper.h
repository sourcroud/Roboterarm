//
// Created by sourc on 30.10.2024.
//
// Literature:
// https://docs.arduino.cc/learn/electronics/servo-motors/
// https://docs.arduino.cc/libraries/servo/

#ifndef ROBOTERARM_SERVOWRAPPER_H
#define ROBOTERARM_SERVOWRAPPER_H

#define OPEN 0
#define CLOSE 1

#include "RoboticArm.h"
#include <Servo.h>


class ServoWrapper {
private:
    RoboticArm &gripper;
    int pos;
    unsigned long preMillis;
public:
    ServoWrapper(RoboticArm &gripper);
    void openGripper();
    void closeGripper();
    void savePos() const;
};
















/*
class ServoWrapper {
private:
    int initialPin;
    int pos;
    unsigned long preMillis;
    unsigned long interval;
public:
    explicit ServoWrapper(int initialPin);
    void moveServo(int direction);
};



*/

#endif //ROBOTERARM_SERVOWRAPPER_H