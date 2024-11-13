//
// Created by sourc on 30.10.2024.
//

#include "JoyStick.h"
#include "Arduino.h"

JoyStick::JoyStick(int xPin, int yPin, int selPin)
:xPin(xPin), yPin(yPin), selPin(selPin)
{

}

int JoyStick::getXVal() {
    int xVal = analogRead(xPin);
    return xVal;
}

int JoyStick::getYVal() {
    int yVal = analogRead(yPin);
    return yVal;
}

bool JoyStick::getState() {
    int selVal = digitalRead(selPin);
    if(selVal == HIGH)return true;
    else return false;
}


