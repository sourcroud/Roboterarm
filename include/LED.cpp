//
// Created by sourc on 30.10.2024.
//

#include "LED.h"
#include <Arduino.h>

LED::LED(int initialPin) : initialPin(initialPin) {
}

void LED::setState(bool state) {
    if(state) {
        digitalWrite(initialPin, HIGH);
    }
    else digitalWrite(initialPin, LOW);
}

void LED::switchOn() {
    setState(true);
}

void LED::switchOff() {
    setState(false);
}


