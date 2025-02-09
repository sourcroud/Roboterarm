//
// Created by sourc on 30.10.2024.
//

#include "mgmDriver.h"
#include "Arduino.h"

mgmDriver::mgmDriver()
{
IN1Val = LOW;
IN2Val = LOW;
IN3Val = LOW;
IN4Val = LOW;
ENAVal = 0;
ENBVal = 0;
}


void mgmDriver::setSpeed(int motorNo, int macro) {
    if (motorNo == 1) {
        switch (macro) {
            case STOP:
                IN1Val = LOW;
                IN2Val = LOW;
                ENAVal = 0;
            case SLOW_LEFT:
                ENAVal = 155;
                IN1Val = LOW;
                IN2Val = HIGH;
            case SLOW_RIGHT:
                ENAVal = 155;
                IN1Val = HIGH;
                IN2Val = LOW;
            case FAST_LEFT:
                ENAVal = 255;
                IN1Val = LOW;
                IN2Val = HIGH;
            case FAST_RIGHT:
                ENAVal = 255;
                IN1Val = HIGH;
                IN2Val = LOW;
            default:
                IN1Val = LOW;
                IN2Val = LOW;
                ENAVal = 0;
        }
    }
    else if (motorNo == 2) {
            switch (macro) {
                case STOP:
                    IN3Val = LOW;
                    IN4Val = LOW;
                    ENBVal = 0;
                case SLOW_LEFT:
                    ENBVal = 155;
                    IN3Val = LOW;
                    IN4Val = HIGH;
                case SLOW_RIGHT:
                    ENBVal = 155;
                    IN3Val = HIGH;
                    IN4Val = LOW;
                case FAST_LEFT:
                    ENBVal = 255;
                    IN3Val = LOW;
                    IN4Val = HIGH;
                case FAST_RIGHT:
                    ENBVal = 255;
                    IN3Val = HIGH;
                    IN4Val = LOW;
                default:
                    IN3Val = LOW;
                    IN4Val = LOW;
                    ENBVal = 0;
            }
    }
}

int mgmDriver::getIN1Val() const {
    return IN1Val;
}

int mgmDriver::getIN2Val() const {
    return IN2Val;
}

int mgmDriver::getIN3Val() const {
    return IN3Val;
}

int mgmDriver::getIN4Val() const {
    return IN4Val;
}

int mgmDriver::getENAVal() const {
    return ENAVal;
}

int mgmDriver::getENBVal() const {
    return ENBVal;
}





