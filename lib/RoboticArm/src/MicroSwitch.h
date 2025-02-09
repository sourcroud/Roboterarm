//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_MICROSWITCH_H
#define ROBOTERARM_MICROSWITCH_H


class MicroSwitch {
private:
    int switchState;
    bool getState() const;
public:
    explicit MicroSwitch();
    bool isOpen() const;
    bool isClosed() const;
    void setState(int microSwitchState);
};


#endif //ROBOTERARM_MICROSWITCH_H
