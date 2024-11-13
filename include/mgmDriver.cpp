//
// Created by sourc on 30.10.2024.
//

#include "mgmDriver.h"
#include "Arduino.h"

mgmDriver::mgmDriver(int IN1Pin, int IN2Pin, int IN3Pin, int IN4Pin, int ENAPin, int ENBPin)
:IN1Pin(IN1Pin), IN2Pin(IN2Pin), IN3Pin(IN3Pin), IN4Pin(IN4Pin), ENAPin(ENAPin), ENBPin(ENBPin)
{

}


void mgmDriver::setSpeed(int motorNo, int macro) const {
    if (motorNo == 1) {
        switch (macro) {
            case STOP:
                digitalWrite(IN1Pin, LOW);
                digitalWrite(IN2Pin, LOW);
            case SLOW_LEFT:
                analogWrite(ENAPin, 155);
                digitalWrite(IN1Pin, LOW);
                digitalWrite(IN2Pin, HIGH);
            case SLOW_RIGHT:
                analogWrite(ENAPin, 155);
                digitalWrite(IN1Pin, HIGH);
                digitalWrite(IN2Pin, LOW);
            case FAST_LEFT:
                analogWrite(ENAPin, 255);
                digitalWrite(IN1Pin, LOW);
                digitalWrite(IN2Pin, HIGH);
            case FAST_RIGHT:
                analogWrite(ENAPin, 255);
                digitalWrite(IN1Pin, HIGH);
                digitalWrite(IN2Pin, LOW);
            default:
                digitalWrite(IN1Pin, LOW);
                digitalWrite(IN2Pin, LOW);
        }
    }
    else if (motorNo == 2) {
        switch (macro) {
            case STOP:
                digitalWrite(IN3Pin, LOW);
                digitalWrite(IN4Pin, LOW);
            case SLOW_LEFT:
                analogWrite(ENBPin, 155);
                digitalWrite(IN3Pin, LOW);
                digitalWrite(IN4Pin, HIGH);
            case SLOW_RIGHT:
                analogWrite(ENBPin, 155);
                digitalWrite(IN3Pin, HIGH);
                digitalWrite(IN4Pin, LOW);
            case FAST_LEFT:
                analogWrite(ENBPin, 255);
                digitalWrite(IN3Pin, LOW);
                digitalWrite(IN4Pin, HIGH);
            case FAST_RIGHT:
                analogWrite(ENBPin, 255);
                digitalWrite(IN3Pin, HIGH);
                digitalWrite(IN4Pin, LOW);
            default:
                digitalWrite(IN3Pin, LOW);
                digitalWrite(IN4Pin, LOW);
        }
    }
}





