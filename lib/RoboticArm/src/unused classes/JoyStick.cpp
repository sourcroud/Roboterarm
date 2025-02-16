//
// Created by sourc on 30.10.2024.
//

#include "JoyStick.h"
#include "Arduino.h"

JoyStick::JoyStick()
{
    xVal = 0;
    yVal = 0;
    selectButtonState = false;
}

int JoyStick::getXVal() const {
    return xVal;
}

int JoyStick::getYVal() const {
    return yVal;
}

bool JoyStick::getSelectState() const {
    return selectButtonState;
}

void JoyStick::setXVal(int x) {
    xVal = x;
}

void JoyStick::setYVal(int y) {
    yVal = y;
}

void JoyStick::setSelectState(bool buttonState) {
    if (buttonState)this->selectButtonState = true;
    else this->selectButtonState = false;
}
