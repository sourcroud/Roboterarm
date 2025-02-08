//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_JOYSTICK_H
#define ROBOTERARM_JOYSTICK_H


class JoyStick {
private:
    int xVal;
    int yVal;
    bool selectButtonPressed;

public:
    explicit JoyStick();
    int getXVal();
    int getYVal();
    bool isSelectButtonPressed();
    void setXVal(int x);
    void setYVal(int y);
    void setSelectButton(int buttonState);
};


#endif //ROBOTERARM_JOYSTICK_H
