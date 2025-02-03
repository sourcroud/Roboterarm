//
// Created by sourc on 30.10.2024.
//

#include "LED.h"
#include <Arduino.h>

#define flashInterval 500 // ms

LED::LED(int initialPin) : initialPin(initialPin) {
    preMillis = 0;
    ledState = false;
}

void LED::setState(bool state) const {
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

void LED::flashLED() {
    unsigned long currentMillis = millis();
    if(currentMillis - preMillis >= flashInterval) { // Sind flashInterval ms vergangen?
        preMillis = currentMillis; // Zeitstempel aktualisieren
        ledState = !ledState; // LED-Zustand umschalten, egal welcher Zustand vorliegt
        // Compiler scheint ledState = !ledState; falsch zu interpretieren.
        // Unreachable Code kann ignoriert werden!
        if(ledState) {
            digitalWrite(initialPin, HIGH);
        }
        else digitalWrite(initialPin, LOW);
    }
}


