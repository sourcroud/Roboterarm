//
// Created by sourc on 30.10.2024.
//

#include "MicroSwitch.h"
#include "Arduino.h"

MicroSwitch::MicroSwitch()
{
    switchState = false;
}

bool MicroSwitch::getState() const {
    return switchState;
}
// isOpen when LOW (NO = Normally Open)
bool MicroSwitch::isOpen() const {
    return !switchState;
}

bool MicroSwitch::isClosed() const {
    return switchState;
}

void MicroSwitch::setState(int microSwitchState) {
    if (microSwitchState == HIGH)switchState = true;
    else switchState = false;
}
