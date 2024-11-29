//
// Created by sourc on 30.10.2024.
//

#include "ServoMotor.h"
#include "Arduino.h"
#include "Servo.h"

















/*
ServoMotor::ServoMotor(int initialPin)
:initialPin(initialPin)
{
pos = 90;

int decPosZeroPoint = pos * 55;
analogWrite(initialPin, decPosZeroPoint);
}

// Siehe Miuzei Lesson 16 Sweep.pdf

void ServoMotor::moveServo(int direction) {
    if(direction == OPEN) {
        for (; pos <= 180; pos += 1) {
            int decPos = pos * 50;
            analogWrite(initialPin, decPos);
            delay(15);       // Vorgabe aus Miuzei Lesson 16 Sweep.pdf
    }
    }
    else if(direction == CLOSE) {
        for(; pos >= 0; pos -=1) {
            int decPos = pos * 50;
            analogWrite(initialPin, decPos);
            delay(15);       // Vorgabe aus Miuzei Lesson 16 Sweep.pdf
        }
    }
}
*/

