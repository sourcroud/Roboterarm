//
// Created by sourc on 31.10.2024.
//

#include "FSMRoboticArm.h"
#include "RoboticArm.h"
#include "JoyStick.h"
#include "LED.h"
//#include "mgmDriver.h"
#include "MicroSwitch.h"
#include "ServoMotor.h"
#include "TouchSensor.h"

#define DEBUG

FSMRoboticArm::FSMRoboticArm(RoboticArm& roboticArm)
:roboticArm(roboticArm)
{
currentState = RoboticArmState::INITIALZUSTAND;
}

// DO's
void FSMRoboticArm::evalState() {                                        // state no.
    switch (currentState) {
        case RoboticArmState::INITIALZUSTAND:                            // 1
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
        break;                                                           // 2
        case RoboticArmState::BETRIEBSBEREIT:
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::LEFTTURN:                                  // 3
            roboticArm.mgmDriver1.setSpeed(1, SLOW_LEFT);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::RIGHTTURN:                                 // 4
            roboticArm.mgmDriver1.setSpeed(1, SLOW_RIGHT);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::REARARMUP:                                 // 5
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, SLOW_LEFT);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::REARARMDOWN:                               // 6
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, SLOW_RIGHT);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::MIDDLEARMUP:                               // 7
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, SLOW_LEFT);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::MIDDLEARMDOWN:                             // 8
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, SLOW_RIGHT);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::FRONTARMUP:                                // 9
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, SLOW_LEFT);
            break;
        case RoboticArmState::FRONTARMDOWN:                                // 10
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, SLOW_RIGHT);
            break;
        case RoboticArmState::CLOSEGRIPPER:                                // 11
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, SLOW_RIGHT);
            roboticArm.servoMotor.moveServo(CLOSE);
            break;
        case RoboticArmState::OPENGRIPPER:                                // 12
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, SLOW_RIGHT);
            roboticArm.servoMotor.moveServo(OPEN);
            break;
        default:
#ifdef DEBUG
        Serial.print("WARNING! You should never see this!\n");
#endif
    }

}

void FSMRoboticArm::evalTransition() {
    RoboticArmState nextState = currentState;
    switch (currentState) {                                              // state no.

        case RoboticArmState::INITIALZUSTAND:                            // 1
        Serial.print("INITIALZUSTAND");
        if(roboticArm.touchSensor.isTouched()) {
            nextState = RoboticArmState::BETRIEBSBEREIT;
        } break;

        case RoboticArmState::BETRIEBSBEREIT:                            // 2
        if(roboticArm.touchSensor.isTouched()) {
            nextState = RoboticArmState::INITIALZUSTAND;
        }
        else if(roboticArm.gripperButton1.isPressed()) {
            nextState = RoboticArmState::OPENGRIPPER;
        }
        else if(roboticArm.gripperButton2.isPressed()) {
            nextState = RoboticArmState::CLOSEGRIPPER;
        }
        else if(roboticArm.joyStick1.getXVal() >= 10) {    // right
            nextState = RoboticArmState::RIGHTTURN;
        }
        else if(roboticArm.joyStick1.getXVal() <= -10) {   // left
            nextState = RoboticArmState::LEFTTURN;
        }
        else if(roboticArm.joyStick2.getXVal() >= 10) {    // right
            nextState = RoboticArmState::FRONTARMUP;
        }
        else if(roboticArm.joyStick2.getXVal() <= -10) {   // left
            nextState = RoboticArmState::FRONTARMDOWN;
        }
        else if(roboticArm.joyStick1.getYVal() >= 10) {
            nextState = RoboticArmState::REARARMDOWN;
        }
        else if(roboticArm.joyStick1.getYVal() <= -10) {
            nextState = RoboticArmState::REARARMUP;
        }
        else if(roboticArm.joyStick2.getYVal() >= 10) {
            nextState = RoboticArmState::MIDDLEARMDOWN;
        }
        else if(roboticArm.joyStick2.getYVal() <= -10) {
            nextState = RoboticArmState::MIDDLEARMUP;
        }
        break;
    }
}
