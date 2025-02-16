//
// Created by sourc on 30.10.2024.
//

#include "ServoWrapper.h"
#include "Arduino.h"
#define servoDelay 10 // ms



ServoWrapper::ServoWrapper()
:pos(90), preMillis(0)
{

}

// Annahme:   0° = Nullpunkt = Gripper vollkommen geschlossen
//          180° = Vollständig geöffnet

void ServoWrapper::openGripper() {
    unsigned long currentMillis = millis();
    if(currentMillis - preMillis >= servoDelay) {   // Sind servoDelay ms vergangen?
        preMillis = currentMillis;  // Zeitstempel aktualisieren
        if(this->pos >= 0 && this->pos < 180) {
            this->pos += 1;
        }
    }
}

void ServoWrapper::closeGripper() {
    unsigned long currentMillis = millis();
    if(currentMillis - preMillis >= servoDelay) { // Sind flashInterval ms vergangen?
        preMillis = currentMillis; // Zeitstempel aktualisieren
        if(pos <= 180 && pos > 0) {
            this->pos -= 1;
        }
    }
}

void ServoWrapper::setPos(int posVal) {
    pos = posVal;
}

int ServoWrapper::getPos() const {
    return pos;
}


