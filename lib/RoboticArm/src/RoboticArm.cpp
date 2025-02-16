//
// Created by sourc on 30.10.2024.
//

#include "RoboticArm.h"
#include "iomasks.h"

RoboticArm::RoboticArm()
:
        ledGreen(),
        ledYellow(),
        ledRed(),
        mgmDriver1(),
        mgmDriver2(),
        microSwitch1(),
        microSwitch2(),
        microSwitch3(),
        microSwitch4(),
        gripper(),
        servo(),
        ps2x()
{
    lastServoPos = 0;
    error = 0;
}

RoboticArm::~RoboticArm() {
    servo.detach();
}

void RoboticArm::updateSensors() {
    ps2x.read_gamepad();
    microSwitch1.setState(digitalRead(microSwitch1Pin));
    microSwitch2.setState(digitalRead(microSwitch2Pin));
    microSwitch3.setState(digitalRead(microSwitch3Pin));
    microSwitch4.setState(digitalRead(microSwitch4Pin));

    gripper.setPos(servo.read());
}

void RoboticArm::updateActuators() {
    digitalWrite(ledGreenPin, ledGreen.getState());
    digitalWrite(ledYellowPin, ledYellow.getState());
    digitalWrite(ledRedPin, ledRed.getState());
    digitalWrite(mgmDriver1IN1Pin, mgmDriver1.getIN1Val());

    digitalWrite(mgmDriver1IN2Pin, mgmDriver1.getIN2Val());
    digitalWrite(mgmDriver1IN3Pin, mgmDriver1.getIN3Val());
    digitalWrite(mgmDriver1IN4Pin, mgmDriver1.getIN4Val());
    analogWrite(mgmDriver1ENAPin, mgmDriver1.getENAVal());
    analogWrite(mgmDriver1ENBPin, mgmDriver1.getENBVal());

    digitalWrite(mgmDriver2IN1Pin, mgmDriver2.getIN1Val());
    digitalWrite(mgmDriver2IN2Pin, mgmDriver2.getIN2Val());
    digitalWrite(mgmDriver2IN3Pin, mgmDriver2.getIN3Val());
    digitalWrite(mgmDriver2IN4Pin, mgmDriver2.getIN4Val());
    analogWrite(mgmDriver2ENAPin, mgmDriver2.getENAVal());
    analogWrite(mgmDriver2ENBPin, mgmDriver2.getENBVal());

    int newPos = gripper.getPos();
    if(abs(newPos - lastServoPos) > 2) { // 2° Deadband, damit kleine Änderungen ignoriert werden
        servo.write(constrain(newPos, 0, 180));
        lastServoPos = newPos;
    }
}

void RoboticArm::initPS2Controller(int clock, int command, int attention, int data, bool pressures, bool rumble) {
    this->error = 0;
    byte type = 0;
    byte vibrate = 0;
    this->error = ps2x.config_gamepad(clock, command, attention, data, pressures, rumble);   //GamePad(clock, command, attention, data, Pressures?, Rumble?)

    if(this->error == 0){
        Serial.println("Found Controller, configured successful");
        Serial.println("Go to www.billporter.info for updates and to report bugs.");
    }

    else if(this->error == 1)
        Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");

    else if(this->error == 2)
        Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");

    else if(this->error == 3)
        Serial.println("Controller refusing to enter Pressures mode, may not support it. ");

    type = ps2x.readType();
    switch(type) {
        case 0:
            Serial.println("Unknown Controller type");
            break;
        case 1:
            Serial.println("DualShock Controller Found");
            break;
        case 2:
            Serial.println("GuitarHero Controller Found");
            break;
    }
}


