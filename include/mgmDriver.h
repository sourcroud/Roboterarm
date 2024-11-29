//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_MGMDRIVER_H
#define ROBOTERARM_MGMDRIVER_H

#include "mgmDriver.h"

#define STOP       0
#define SLOW_LEFT  1
#define SLOW_RIGHT 2
#define FAST_LEFT  3
#define FAST_RIGHT 4

class mgmDriver {
private:
    int IN1Pin;
    int IN2Pin;
    int IN3Pin;
    int IN4Pin;
    int ENAPin;
    int ENBPin;
public:
    explicit mgmDriver(int IN1Pin, int IN2Pin, int IN3Pin, int IN4Pin, int ENAPin, int ENBPin);
    void setSpeed(int motorNo,int macro) const;
};


#endif //ROBOTERARM_MGMDRIVER_H
