//
// Created by sourc on 30.10.2024.
//

#ifndef ROBOTERARM_IOMASKS_H
#define ROBOTERARM_IOMASKS_H

// Pin-Zuweisung

//#define joyStick1XPin A0
//#define joyStick1YPin A1
//#define joyStick1SelPin 48
//#define joyStick2XPin A2
//#define joyStick2YPin A3
//#define joyStick2SelPin 49

#define ledGreenPin 28
#define ledYellowPin 26
#define ledRedPin 27

#define mgmDriver1IN1Pin 30
#define mgmDriver1IN2Pin 31
#define mgmDriver1IN3Pin 32
#define mgmDriver1IN4Pin 33
#define mgmDriver1ENAPin 8  // PWM
#define mgmDriver1ENBPin 9  // PWM

#define mgmDriver2IN1Pin 34
#define mgmDriver2IN2Pin 35
#define mgmDriver2IN3Pin 36
#define mgmDriver2IN4Pin 37
#define mgmDriver2ENAPin 10 // PWM
#define mgmDriver2ENBPin 11 // PWM

#define microSwitch1Pin 22
#define microSwitch2Pin 23
#define microSwitch3Pin 24
#define microSwitch4Pin 25

#define servoMotorPin 5
//#define touchSensorPin 6

//GamePad-Pins:
// clock
#define ps2clock 12
// command
#define ps2command 13
// attention
#define ps2attention 3
// data
#define ps2data 4

//Voreinstellungen
#define zeroPoint 128
#define stickDrift 6

#endif //ROBOTERARM_IOMASKS_H
