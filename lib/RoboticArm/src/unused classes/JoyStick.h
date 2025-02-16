//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_JOYSTICK_H
#define ROBOTERARM_JOYSTICK_H


class JoyStick {
private:
    int xVal;
    int yVal;
    bool selectButtonState;

public:
    explicit JoyStick();

    int getXVal() const;
    int getYVal() const;
    bool getSelectState() const;

    void setXVal(int x);
    void setYVal(int y);
    void setSelectState(bool buttonState);

};


#endif //ROBOTERARM_JOYSTICK_H

/*
 *
 */
