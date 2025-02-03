//
// Created by sourc on 31.10.2024.
//

#ifndef ROBOTERARM_TOUCHSENSOR_H
#define ROBOTERARM_TOUCHSENSOR_H


class TouchSensor {
private:
    int initialPin;
    bool getState() const;
public:
    explicit TouchSensor(int initialPin);
    bool isTouched();
};


#endif //ROBOTERARM_TOUCHSENSOR_H
