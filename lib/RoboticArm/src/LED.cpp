//
// Created by sourc on 30.10.2024.
//

#include "LED.h"
#include <Arduino.h>

#define flashInterval 750 // ms
#define ON 0
#define OFF 1


LED::LED() {
    preMillis = 0;
    ledState = false;
}

int LED::getState() const {
    if(ledState)return HIGH;
    else return LOW;
}

void LED::setState(bool state) {
    ledState = state;
}

void LED::switchOn() {
    setState(true);
}

void LED::switchOff() {
    setState(false);
}

void LED::flashLED() {
    unsigned long currentMillis = millis();
    if (currentMillis - preMillis >= flashInterval) { // Sind flashInterval ms vergangen?
        preMillis = currentMillis; // Zeitstempel aktualisieren
        setState(!ledState); // LED-Zustand umschalten, egal welcher Zustand vorliegt
    }
}



