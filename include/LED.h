//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_LED_H
#define ROBOTERARM_LED_H


class LED {
private:
    int initialPin;
    void setState(bool state);
public:
    explicit LED(int initialPin);
    void switchOn();
    void switchOff();
};


#endif //ROBOTERARM_LED_H
