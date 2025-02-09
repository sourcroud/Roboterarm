//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_LED_H
#define ROBOTERARM_LED_H

class LED {
private:
    bool ledState;
    unsigned long preMillis;
    void setState(bool state);
public:
    explicit LED();
    int getState() const;
    void switchOn();
    void switchOff();
    void flashLED();
};


#endif //ROBOTERARM_LED_H
