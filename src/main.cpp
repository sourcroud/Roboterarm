#include <Arduino.h>
#include "RoboticArm.h"
#include "FSMRoboticArm.h"
#include "ServoWrapper.h"

// initialize digital pins
#include "Pinbelegung.h"

void setup() {
    Serial.begin(9600);
    pinMode(joyStick1XPin, INPUT);
    pinMode(joyStick1YPin, INPUT);
    pinMode(joyStick1SelPin, INPUT);
    pinMode(joyStick2XPin, INPUT);
    pinMode(joyStick2YPin, INPUT);
    pinMode(joyStick2SelPin, INPUT);

    pinMode(ledGreenPin, OUTPUT);
    pinMode(ledYellowPin, OUTPUT);
    pinMode(ledRedPin, OUTPUT);

    pinMode(mgmDriver1IN1Pin, OUTPUT);
    pinMode(mgmDriver1IN2Pin, OUTPUT);
    pinMode(mgmDriver1ENAPin, OUTPUT);
    pinMode(mgmDriver1ENBPin, OUTPUT);

    pinMode(mgmDriver2IN1Pin, OUTPUT);
    pinMode(mgmDriver2IN2Pin, OUTPUT);
    pinMode(mgmDriver2ENAPin, OUTPUT);
    pinMode(mgmDriver2ENBPin, OUTPUT);

    pinMode(microSwitch1Pin, INPUT);
    pinMode(microSwitch2Pin, INPUT);
    pinMode(microSwitch3Pin, INPUT);
    pinMode(microSwitch4Pin, INPUT);

    pinMode(servoMotorPin, OUTPUT);


}

RoboticArm robot;
ServoWrapper gripper(robot);
FSMRoboticArm fsm(robot, gripper);

void loop() {
    fsm.evalTransition();
    fsm.evalState();
}