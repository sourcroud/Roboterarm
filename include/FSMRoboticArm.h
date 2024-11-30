//
// Created by sourc on 31.10.2024.
//

#ifndef ROBOTERARM_FSMROBOTICARM_H
#define ROBOTERARM_FSMROBOTICARM_H
#include "RoboticArm.h"
#include "ServoWrapper.h"

// Enumeration-Klasse enthält benötigte States
enum class RoboticArmState {  // State
    INITIALZUSTAND,           // 1
    BETRIEBSBEREIT,           // 2
    LEFTTURN,                 // 3
    RIGHTTURN,                // 4
    REARARMUP,                // 5
    REARARMDOWN,              // 6
    MIDDLEARMUP,              // 7
    MIDDLEARMDOWN,            // 8
    FRONTARMUP,               // 9
    FRONTARMDOWN,             // 10
    CLOSEGRIPPER,             // 11
    OPENGRIPPER               // 12
};

class FSMRoboticArm {
private:
    RoboticArmState currentState;
    RoboticArm& roboticArm;
    ServoWrapper& gripper;
public:
    explicit FSMRoboticArm(RoboticArm&, ServoWrapper&);
    void evalState();
    void evalTransition();
};

#endif //ROBOTERARM_FSMROBOTICARM_H
