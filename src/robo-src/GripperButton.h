//
// Created by sourc on 31.10.2024.
//

#ifndef ROBOTERARM_GRIPPERBUTTON_H
#define ROBOTERARM_GRIPPERBUTTON_H


class GripperButton {
private:
    int initialPin;
public:
    explicit GripperButton(int initialPin);
    bool isPressed() const;
};


#endif //ROBOTERARM_GRIPPERBUTTON_H
