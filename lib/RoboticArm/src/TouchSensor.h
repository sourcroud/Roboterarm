//
// Created by sourc on 31.10.2024.
//

#ifndef ROBOTERARM_TOUCHSENSOR_H
#define ROBOTERARM_TOUCHSENSOR_H


class TouchSensor {
private:
    int sensorState;
    bool getState() const;
public:
    explicit TouchSensor();
    bool isTouched();
    void setState(int touchSensorState);
};


#endif //ROBOTERARM_TOUCHSENSOR_H
