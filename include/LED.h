//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_LED_H
#define ROBOTERARM_LED_H

class LED {
private:
    int initialPin;
    void setState(bool state) const;
    bool ledState = false;
    unsigned long preMillis;
    unsigned long interval;
public:
    explicit LED(int initialPin);
    void switchOn();
    void switchOff();
    void flashLED();
};


#endif //ROBOTERARM_LED_H
