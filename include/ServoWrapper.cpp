//
// Created by sourc on 30.10.2024.
//

#include "ServoWrapper.h"
#include "Arduino.h"
#include "Servo.h"
#include "EEPROM.h"

#define servoDelay 50 // ms
#define posAddress 0

/*
ServoWrapper::ServoWrapper(int initialPin)
:initialPin(initialPin)
{
pos = 90;

int decPosZeroPoint = pos * 55;
analogWrite(initialPin, decPosZeroPoint);
}

// Siehe Miuzei Lesson 16 Sweep.pdf

void ServoWrapper::moveServo(int direction) {
    if(direction == OPEN) {
        for (; pos <= 180; pos += 1) {
            int decPos = pos * 50;
            analogWrite(initialPin, decPos);
            delay(15);       // Vorgabe aus Miuzei Lesson 16 Sweep.pdf
    }
    }
    else if(direction == CLOSE) {
        for(; pos >= 0; pos -=1) {
            int decPos = pos * 50;
            analogWrite(initialPin, decPos);
            delay(15);       // Vorgabe aus Miuzei Lesson 16 Sweep.pdf
        }
    }
}
*/

ServoWrapper::ServoWrapper(RoboticArm &gripper)
:gripper(gripper), pos(0), preMillis(0)
{
    pos = EEPROM.read(posAddress);
}

// Annahme:   0° = Nullpunkt = Gripper vollkommen geschlossen
//          180° = Vollständig geöffnet

void ServoWrapper::openGripper() {
    unsigned long currentMillis = millis();
    if(currentMillis - preMillis >= servoDelay) {   // Sind servoDelay ms vergangen?
        preMillis = currentMillis;  // Zeitstempel aktualisieren
        if(pos >= 0 && pos < 180) {
            gripper.servo.write(pos += 1);
        }
    }
}

void ServoWrapper::closeGripper() {
    unsigned long currentMillis = millis();
    if(currentMillis - preMillis >= servoDelay) { // Sind flashInterval ms vergangen?
        preMillis = currentMillis; // Zeitstempel aktualisieren
        if(pos <= 180 && pos > 0) {
            gripper.servo.write(pos -= 1);
        }
    }
}

void ServoWrapper::savePos() const {
    EEPROM.write(posAddress, pos);
}
