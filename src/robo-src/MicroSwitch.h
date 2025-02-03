//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_MICROSWITCH_H
#define ROBOTERARM_MICROSWITCH_H


class MicroSwitch {
private:
    int initialPin;
    bool getState();
public:
    explicit MicroSwitch(int initialPin);
    bool isOpen();
    bool isClosed();
};


#endif //ROBOTERARM_MICROSWITCH_H
