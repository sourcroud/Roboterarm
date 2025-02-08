//
// Created by sourc on 31.10.2024.
//

#include "FSMRoboticArm.h"
#include "RoboticArm.h"
#include "ServoWrapper.h"


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
            roboticArm.gripper.closeGripper();
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::OPENGRIPPER:                                // 12
            roboticArm.gripper.openGripper();
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        default:
            roboticArm.ledRed.flashLED();
#ifdef DEBUG
        Serial.print("WARNING! Error in State Evaluation!\n");
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
        else if(roboticArm.joyStick1.isSelectButtonPressed()) {
            nextState = RoboticArmState::OPENGRIPPER;
        }
        else if(roboticArm.joyStick2.isSelectButtonPressed()) {
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
        else if(roboticArm.joyStick1.getYVal() >= 10) {    // down
            nextState = RoboticArmState::REARARMDOWN;
        }
        else if(roboticArm.joyStick1.getYVal() <= -10) {   // up
            nextState = RoboticArmState::REARARMUP;
        }
        else if(roboticArm.joyStick2.getYVal() >= 10) {    // down
            nextState = RoboticArmState::MIDDLEARMDOWN;
        }
        else if(roboticArm.joyStick2.getYVal() <= -10) {   // up
            nextState = RoboticArmState::MIDDLEARMUP;
        } break;

        case RoboticArmState::LEFTTURN:                                  // 3
            if(roboticArm.joyStick1.getXVal() > -10) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::RIGHTTURN:                                 // 4
            if(roboticArm.joyStick1.getXVal() < 10) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::REARARMUP:                                 // 5
            if(roboticArm.joyStick1.getYVal() > -10) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::REARARMDOWN:                               // 6
            if(roboticArm.joyStick1.getYVal() < 10) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::MIDDLEARMUP:                               // 7
            if(roboticArm.joyStick2.getYVal() > -10) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::MIDDLEARMDOWN:                             // 8
            if(roboticArm.joyStick2.getYVal() < 10) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::FRONTARMUP:                                // 9
            if(roboticArm.joyStick2.getXVal() < 10) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::FRONTARMDOWN:                              // 10
            if(roboticArm.joyStick2.getXVal() > -10) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::CLOSEGRIPPER:                              // 11
            if(!roboticArm.joyStick2.isSelectButtonPressed()) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::OPENGRIPPER:                               // 12
        if(!roboticArm.joyStick1.isSelectButtonPressed()) {
            nextState = RoboticArmState::BETRIEBSBEREIT;
        } break;

        default:
            roboticArm.ledRed.flashLED();
#ifdef DEBUG
            Serial.print("WARNING! Error in Transition Evaluation!\n");
#endif
    }
    if(currentState != nextState) {

        switch (currentState) {                                          // Exits

            case RoboticArmState::INITIALZUSTAND:                        // 1
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                roboticArm.ledRed.switchOff();
                break;

            case RoboticArmState::BETRIEBSBEREIT:                        // 2
                roboticArm.ledGreen.switchOff();
                break;

            case RoboticArmState::LEFTTURN:                              // 3
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            case RoboticArmState::RIGHTTURN:                             // 4
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            case RoboticArmState::REARARMUP:                             // 5
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            case RoboticArmState::REARARMDOWN:                           // 6
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            case RoboticArmState::MIDDLEARMUP:                           // 7
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            case RoboticArmState::MIDDLEARMDOWN:                         // 8
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            case RoboticArmState::FRONTARMUP:                            // 9
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            case RoboticArmState::FRONTARMDOWN:                          // 10
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            case RoboticArmState::CLOSEGRIPPER:                          // 11
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            case RoboticArmState::OPENGRIPPER:                           // 12
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                break;

            default:
                roboticArm.ledRed.flashLED();
#ifdef DEBUG
                Serial.print("WARNING! Error in Exit Evaluation!\n");
#endif
        }

        switch (nextState) {                                             // Entries

            case RoboticArmState::INITIALZUSTAND:                        // 1
                roboticArm.ledGreen.flashLED();
                roboticArm.ledYellow.flashLED();
                roboticArm.ledRed.flashLED();
                break;

            case RoboticArmState::BETRIEBSBEREIT:                        // 2
                roboticArm.ledGreen.switchOn();
                break;

            case RoboticArmState::LEFTTURN:                              // 3
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                break;

            case RoboticArmState::RIGHTTURN:                             // 4
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                break;

            case RoboticArmState::REARARMUP:                             // 5
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                break;

            case RoboticArmState::REARARMDOWN:                           // 6
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                break;

            case RoboticArmState::MIDDLEARMUP:                           // 7
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                break;

            case RoboticArmState::MIDDLEARMDOWN:                         // 8
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                break;

            case RoboticArmState::FRONTARMUP:                            // 9
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                break;

            case RoboticArmState::FRONTARMDOWN:                          // 10
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                break;

            case RoboticArmState::CLOSEGRIPPER:                          // 11
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.flashLED();
                break;

            case RoboticArmState::OPENGRIPPER:                           // 12
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.flashLED();
                break;

            default:
                roboticArm.ledRed.flashLED();
#ifdef DEBUG
                Serial.print("WARNING! Error in Entry Evaluation!\n");
#endif
        }
    }
}
