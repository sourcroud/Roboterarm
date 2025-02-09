//
// Created by sourc on 31.10.2024.
//

#include "TouchSensor.h"
#include "Arduino.h"

TouchSensor::TouchSensor()
{
    sensorState = false;
}

bool TouchSensor::getState() const {
    return sensorState;
}

bool TouchSensor::isTouched() {
    if(getState())return true;
    else return false;
}

void TouchSensor::setState(int touchSensorState) {
    if (touchSensorState == HIGH)sensorState = true;
    else sensorState = false;
}


