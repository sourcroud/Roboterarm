//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_SERVOMOTOR_H
#define ROBOTERARM_SERVOMOTOR_H
#define OPEN 0
#define CLOSE 1

#include <Servo.h>


class ServoMotor {
private:
    Servo servo1;
    int initialPin;
    int
};
















/*
class ServoMotor {
private:
    int initialPin;
    int pos;
    unsigned long preMillis;
    unsigned long interval;
public:
    explicit ServoMotor(int initialPin);
    void moveServo(int direction);
};



*/

#endif //ROBOTERARM_SERVOMOTOR_H