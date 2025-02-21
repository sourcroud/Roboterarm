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

// 170 = 6V
#define EN_SLOW 60
#define EN_FAST 150
#define EN_MAX 255

void mgmDriver::setSpeed(int motorNo, int macro) {
    if (motorNo == 1) {
        switch (macro) {
            case STOP:
                Serial.print("Motor 1: STOP.\n");
                IN1Val = LOW;
                IN2Val = LOW;
                ENAVal = EN_MAX;
                break;
            case SLOW_LEFT:
                Serial.print("Motor 1: SLOW_LEFT.\n");
                ENAVal = EN_SLOW;
                IN1Val = LOW;
                IN2Val = HIGH;
                break;
            case SLOW_RIGHT:
                Serial.print("Motor 1: SLOW_RIGHT.\n");
                ENAVal = EN_SLOW;
                IN1Val = HIGH;
                IN2Val = LOW;
                break;
            case FAST_LEFT:
                Serial.print("Motor 1: FAST_LEFT.\n");
                ENAVal = EN_FAST;
                IN1Val = LOW;
                IN2Val = HIGH;
                break;
            case FAST_RIGHT:
                Serial.print("Motor 1: FAST_RIGHT.\n");
                ENAVal = EN_FAST;
                IN1Val = HIGH;
                IN2Val = LOW;
                break;
            default:
                Serial.print("Motor 1: default case.\n");
                IN1Val = LOW;
                IN2Val = LOW;
                ENAVal = EN_MAX;
                break;
        }
    }
    else if (motorNo == 2) {
            switch (macro) {
                case STOP:
                    Serial.print("Motor 2: STOP.\n");
                    IN3Val = LOW;
                    IN4Val = LOW;
                    ENBVal = EN_MAX;
                    break;
                case SLOW_LEFT:
                    Serial.print("Motor 2: SLOW_LEFT.\n");
                    ENBVal = EN_SLOW;
                    IN3Val = LOW;
                    IN4Val = HIGH;
                    break;
                case SLOW_RIGHT:
                    Serial.print("Motor 2: SLOW_RIGHT.\n");
                    ENBVal = EN_SLOW;
                    IN3Val = HIGH;
                    IN4Val = LOW;
                    break;
                case FAST_LEFT:
                    Serial.print("Motor 2: FAST_LEFT.\n");
                    ENBVal = EN_FAST;
                    IN3Val = LOW;
                    IN4Val = HIGH;
                    break;
                case FAST_RIGHT:
                    Serial.print("Motor 2: FAST_RIGHT.\n");
                    ENBVal = EN_FAST;
                    IN3Val = HIGH;
                    IN4Val = LOW;
                    break;
                default:
                    Serial.print("Motor 2: default case.\n");
                    IN3Val = LOW;
                    IN4Val = LOW;
                    ENBVal = EN_MAX;
                    break;
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





