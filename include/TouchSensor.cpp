//
// Created by sourc on 31.10.2024.
//

#include "TouchSensor.h"
#include "Arduino.h"

TouchSensor::TouchSensor(int initialPin)
:initialPin(initialPin)
{

}

bool TouchSensor::getState() const {
    bool touch_stat = false;
    touch_stat = digitalRead(initialPin);
    return touch_stat;
}

bool TouchSensor::isTouched() {
    if(getState())return true;
    else return false;
}


