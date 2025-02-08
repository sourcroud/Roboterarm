//
// Created by sourc on 30.10.2024.
//

#include "RoboticArm.h"
#include "iomasks.h"

RoboticArm::RoboticArm()
:
        joyStick1(),
        joyStick2(),
        ledGreen(),
        ledYellow(),
        ledRed(),
        mgmDriver1(),
        mgmDriver2(),
        microSwitch1(),
        microSwitch2(),
        microSwitch3(),
        microSwitch4(),
        touchSensor(),
        gripper(),
        servo()
{
    servo.attach(servoMotorPin);
    lastServoPos = -1;
}

RoboticArm::~RoboticArm() {
    servo.detach();
}

void RoboticArm::updateSensors() {
    joyStick1.setXVal(analogRead(joyStick1XPin));
    joyStick1.setYVal(analogRead(joyStick1YPin));
    joyStick1.setSelectButton(digitalRead(joyStick1SelPin));

    joyStick2.setXVal(analogRead(joyStick2XPin));
    joyStick2.setYVal(analogRead(joyStick2YPin));
    joyStick2.setSelectButton(digitalRead(joyStick2SelPin));

    microSwitch1.setState(digitalRead(microSwitch1Pin));
    microSwitch2.setState(digitalRead(microSwitch2Pin));
    microSwitch3.setState(digitalRead(microSwitch3Pin));
    microSwitch4.setState(digitalRead(microSwitch4Pin));

    touchSensor.setState(digitalRead(touchSensorPin));

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
    if(newPos != this->lastServoPos) {
        servo.write(constrain(newPos, 0, 180));
        lastServoPos = newPos;
    }
}


