//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_SERVOMOTOR_H
#define ROBOTERARM_SERVOMOTOR_H
#define OPEN 0
#define CLOSE 1


class ServoMotor {
private:
    int initialPin;
    int pos;
public:
    explicit ServoMotor(int initialPin);
    void moveServo(int direction);
};


#endif //ROBOTERARM_SERVOMOTOR_H
