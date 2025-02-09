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
    int IN1Val;
    int IN2Val;
    int IN3Val;
    int IN4Val;
    int ENAVal;
    int ENBVal;
public:
    explicit mgmDriver();
    void setSpeed(int motorNo,int macro);
    int getIN1Val() const;
    int getIN2Val() const;
    int getIN3Val() const;
    int getIN4Val() const;
    int getENAVal() const;
    int getENBVal() const;
};


#endif //ROBOTERARM_MGMDRIVER_H
