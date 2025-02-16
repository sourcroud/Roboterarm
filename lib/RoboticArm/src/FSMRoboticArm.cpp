//
// Created by sourc on 31.10.2024.
//

#include "FSMRoboticArm.h"
#include "RoboticArm.h"
#include "iomasks.h"


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
        Serial.print("evalState: INITIALZUSTAND.\n");
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;                                                       // 2
        case RoboticArmState::BETRIEBSBEREIT:
            Serial.print("evalState: BETRIEBSBEREIT.\n");
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::LEFTTURN:                                  // 3
            Serial.print("evalState: LEFTTURN.\n");
            roboticArm.mgmDriver1.setSpeed(1, SLOW_LEFT);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::RIGHTTURN:                                 // 4
            Serial.print("evalState: RIGHTTURN.\n");
            roboticArm.mgmDriver1.setSpeed(1, SLOW_RIGHT);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::REARARMUP:                                 // 5
            Serial.print("evalState: REARARMUP.\n");
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, SLOW_LEFT);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::REARARMDOWN:                               // 6
            Serial.print("evalState: REARARMDOWN.\n");
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, SLOW_RIGHT);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::MIDDLEARMUP:                               // 7
            Serial.print("evalState: MIDDLEARMUP.\n");
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, SLOW_LEFT);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::MIDDLEARMDOWN:                             // 8
            Serial.print("evalState: MIDDLEARMDOWN.\n");
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, SLOW_RIGHT);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::FRONTARMUP:                                // 9
            Serial.print("evalState: FRONTARMUP.\n");
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, SLOW_LEFT);
            break;
        case RoboticArmState::FRONTARMDOWN:                                // 10
            Serial.print("evalState: FRONTARMDOWN.\n");
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, SLOW_RIGHT);
            break;
        case RoboticArmState::CLOSEGRIPPER:                                // 11
            Serial.print("evalState: CLOSEGRIPPER.\n");
            roboticArm.gripper.closeGripper();
            roboticArm.mgmDriver1.setSpeed(1, STOP);
            roboticArm.mgmDriver1.setSpeed(2, STOP);
            roboticArm.mgmDriver2.setSpeed(1, STOP);
            roboticArm.mgmDriver2.setSpeed(2, STOP);
            break;
        case RoboticArmState::OPENGRIPPER:                                // 12
            Serial.print("evalState: OPENGRIPPER.\n");
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
        Serial.print("evalTransition: INITIALZUSTAND.\n");
        if(roboticArm.ps2x.ButtonPressed(PSB_START)) {
            nextState = RoboticArmState::BETRIEBSBEREIT;
        } break;

        case RoboticArmState::BETRIEBSBEREIT:
        Serial.print("evalTransition: BETRIEBSBEREIT.\n");                     // 2
        if(roboticArm.ps2x.ButtonPressed(PSB_SELECT)) {
            nextState = RoboticArmState::INITIALZUSTAND;
        }
        else if(roboticArm.ps2x.ButtonPressed(PSB_L2)) {
            nextState = RoboticArmState::OPENGRIPPER;
        }
        else if(roboticArm.ps2x.ButtonPressed(PSB_R2)) {
            nextState = RoboticArmState::CLOSEGRIPPER;
        }
        else if(roboticArm.ps2x.Analog(PSS_LX) >= (zeroPoint+stickDrift)) {    // left x
            nextState = RoboticArmState::RIGHTTURN;
        }
        else if(roboticArm.ps2x.Analog(PSS_LX) <= (zeroPoint-stickDrift)) {   // left x
            nextState = RoboticArmState::LEFTTURN;
        }
        else if(roboticArm.ps2x.Analog(PSS_RX) >= (zeroPoint+stickDrift)) {    // right x
            nextState = RoboticArmState::FRONTARMUP;
        }
        else if(roboticArm.ps2x.Analog(PSS_RX) <= (zeroPoint-stickDrift)) {   // right x
            nextState = RoboticArmState::FRONTARMDOWN;
        }
        else if(roboticArm.ps2x.Analog(PSS_LY) >= (zeroPoint+stickDrift)) {    // left y
            nextState = RoboticArmState::REARARMDOWN;
        }
        else if(roboticArm.ps2x.Analog(PSS_LY) <= (zeroPoint-stickDrift)) {   // left y
            nextState = RoboticArmState::REARARMUP;
        }
        else if(roboticArm.ps2x.Analog(PSS_RY) >= (zeroPoint+stickDrift)) {    // right y
            nextState = RoboticArmState::MIDDLEARMDOWN;
        }
        else if(roboticArm.ps2x.Analog(PSS_RY) <= (zeroPoint-stickDrift)) {   // right y
            nextState = RoboticArmState::MIDDLEARMUP;
        } break;

        case RoboticArmState::LEFTTURN:                                  // 3
            Serial.print("evalTransition: LEFTTURN.\n");
            if(roboticArm.ps2x.Analog(PSS_LX) > (zeroPoint-stickDrift)) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::RIGHTTURN:                                 // 4
            Serial.print("evalTransition: RIGHTTURN.\n");
            if(roboticArm.ps2x.Analog(PSS_LX) < (zeroPoint+stickDrift)) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::REARARMUP:                                 // 5
            Serial.print("evalTransition: REARARMUP.\n");
            if(roboticArm.ps2x.Analog(PSS_LY) > (zeroPoint-stickDrift)) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::REARARMDOWN:                               // 6
            Serial.print("evalTransition: REARARMDOWN.\n");
            if(roboticArm.ps2x.Analog(PSS_LY) < (zeroPoint+stickDrift)) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::MIDDLEARMUP:                               // 7
            Serial.print("evalTransition: MIDDLEARMUP.\n");
            if(roboticArm.ps2x.Analog(PSS_RY) > (zeroPoint-stickDrift)) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::MIDDLEARMDOWN:                             // 8
            Serial.print("evalTransition: MIDDLEARMDOWN.\n");
            if(roboticArm.ps2x.Analog(PSS_RY) < (zeroPoint+stickDrift)) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::FRONTARMUP:                                // 9
            Serial.print("evalTransition: FRONTARMUP.\n");
            if(roboticArm.ps2x.Analog(PSS_RX) < (zeroPoint+stickDrift)) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::FRONTARMDOWN:                              // 10
            Serial.print("evalTransition: FRONTARMDOWN.\n");
            if(roboticArm.ps2x.Analog(PSS_RX) > (zeroPoint-stickDrift)) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::CLOSEGRIPPER:                              // 11
            Serial.print("evalTransition: CLOSEGRIPPER.\n");
            if(roboticArm.ps2x.ButtonReleased(PSB_R2)) {
                nextState = RoboticArmState::BETRIEBSBEREIT;
            } break;

        case RoboticArmState::OPENGRIPPER:                               // 12
            Serial.print("evalTransition: OPENGRIPPER.\n");
        if(roboticArm.ps2x.ButtonReleased(PSB_L2)) {
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
                Serial.print("INITIALZUSTAND: Exit.\n");
                break;

            case RoboticArmState::BETRIEBSBEREIT:                        // 2
                roboticArm.ledGreen.switchOff();
                Serial.print("BETRIEBSBEREIT: Exit.\n");
                break;

            case RoboticArmState::LEFTTURN:                              // 3
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("LEFTTURN: Exit.\n");
                break;

            case RoboticArmState::RIGHTTURN:                             // 4
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("RIGHTTURN: Exit.\n");
                break;

            case RoboticArmState::REARARMUP:                             // 5
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("REARARMUP: Exit.\n");
                break;

            case RoboticArmState::REARARMDOWN:                           // 6
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("REARARMDOWN: Exit.\n");
                break;

            case RoboticArmState::MIDDLEARMUP:                           // 7
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("MIDDLEARMUP: Exit.\n");
                break;

            case RoboticArmState::MIDDLEARMDOWN:                         // 8
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("MIDDLEARMDOWN: Exit.\n");
                break;

            case RoboticArmState::FRONTARMUP:                            // 9
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("FRONTARMUP: Exit.\n");
                break;

            case RoboticArmState::FRONTARMDOWN:                          // 10
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("FRONTARMDOWN: Exit.\n");
                break;

            case RoboticArmState::CLOSEGRIPPER:                          // 11
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("CLOSEGRIPPER: Exit.\n");
                break;

            case RoboticArmState::OPENGRIPPER:                           // 12
                roboticArm.ledGreen.switchOff();
                roboticArm.ledYellow.switchOff();
                Serial.print("OPENGRIPPER: Exit.\n");
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
                Serial.print("INITIALZUSTAND: Entry.\n");
                break;

            case RoboticArmState::BETRIEBSBEREIT:                        // 2
                roboticArm.ledGreen.switchOn();
                Serial.print("BETRIEBSBEREIT: Entry.\n");
                break;

            case RoboticArmState::LEFTTURN:                              // 3
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                Serial.print("LEFTTURN: Entry.\n");
                break;

            case RoboticArmState::RIGHTTURN:                             // 4
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                Serial.print("RIGHTTURN: Entry.\n");
                break;

            case RoboticArmState::REARARMUP:                             // 5
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                Serial.print("REARARMUP: Entry.\n");
                break;

            case RoboticArmState::REARARMDOWN:                           // 6
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                Serial.print("REARARMDOWN: Entry.\n");
                break;

            case RoboticArmState::MIDDLEARMUP:                           // 7
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                Serial.print("MIDDLEARMUP: Entry.\n");
                break;

            case RoboticArmState::MIDDLEARMDOWN:                         // 8
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                Serial.print("MIDDLEARMDOWN: Entry.\n");
                break;

            case RoboticArmState::FRONTARMUP:                            // 9
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                Serial.print("FRONTARMUP: Entry.\n");
                break;

            case RoboticArmState::FRONTARMDOWN:                          // 10
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.switchOn();
                Serial.print("FRONTARMDOWN: Entry.\n");
                break;

            case RoboticArmState::CLOSEGRIPPER:                          // 11
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.flashLED();
                Serial.print("CLOSEGRIPPER: Entry.\n");
                break;

            case RoboticArmState::OPENGRIPPER:                           // 12
                roboticArm.ledGreen.switchOn();
                roboticArm.ledYellow.flashLED();
                Serial.print("OPENGRIPPER: Entry.\n");
                break;

            default:
                roboticArm.ledRed.flashLED();
#ifdef DEBUG
                Serial.print("WARNING! Error in Entry Evaluation!\n");
#endif
        }
        currentState = nextState;
    }

}
