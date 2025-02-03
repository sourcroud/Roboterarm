//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_JOYSTICK_H
#define ROBOTERARM_JOYSTICK_H


class JoyStick {
private:
    int xPin;
    int yPin;
    int selPin;

public:
    explicit JoyStick(int xPin, int yPin, int selPin);
    int getXVal();
    int getYVal();
    bool isPressed();
};


#endif //ROBOTERARM_JOYSTICK_H
