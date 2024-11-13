//
// Created by sourc on 30.10.2024.
//

#include "MicroSwitch.h"
#include "Arduino.h"

MicroSwitch::MicroSwitch(int initialPin)
:initialPin(initialPin)
{

}

bool MicroSwitch::getState() {
    int msVal = digitalRead(initialPin);
    if(msVal == HIGH)return true;
    else return false;
}

bool MicroSwitch::isOpen() {
    if(getState())return false;
    else return true;
}

bool MicroSwitch::isClosed() {
    if(!getState())return true;
    else return false;
}
