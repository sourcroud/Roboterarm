//
// Created by sourc on 30.10.2024.
//

#include "JoyStick.h"
#include "Arduino.h"

JoyStick::JoyStick()
{
    xVal = 0;
    yVal = 0;
    selectButtonPressed = false;
}

int JoyStick::getXVal() {
    return xVal;
}

int JoyStick::getYVal() {
    return yVal;
}

bool JoyStick::isSelectButtonPressed() {
    return selectButtonPressed;
}

void JoyStick::setXVal(int x) {
    xVal = x;
}

void JoyStick::setYVal(int y) {
    yVal = y;
}

void JoyStick::setSelectButton(int buttonState) {
    if (buttonState == HIGH)selectButtonPressed = true;
    else selectButtonPressed = false;
}


