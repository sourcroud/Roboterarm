//
// Created by sourc on 31.10.2024.
//

#include "GripperButton.h"
#include "Arduino.h"

GripperButton::GripperButton(int initialPin)
:initialPin(initialPin)
{

}

bool GripperButton::isPressed() const {
    if(digitalRead(initialPin) == HIGH)return true;
    else return false;
}
