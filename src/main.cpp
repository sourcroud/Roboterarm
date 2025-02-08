#include <Arduino.h>
#include "robo-src/RoboticArm.h"
#include "robo-src/FSMRoboticArm.h"

// initialize digital pins
#include "robo-src/iomasks.h"

void setup() {
    Serial.begin(9600);
    pinMode(joyStick1XPin, INPUT);
    pinMode(joyStick1YPin, INPUT);
    pinMode(joyStick1SelPin, INPUT);
    pinMode(joyStick2XPin, INPUT);
    pinMode(joyStick2YPin, INPUT);
    pinMode(joyStick2SelPin, INPUT);

    pinMode(ledGreenPin, OUTPUT);
    pinMode(ledYellowPin, OUTPUT);
    pinMode(ledRedPin, OUTPUT);

    pinMode(mgmDriver1IN1Pin, OUTPUT);
    pinMode(mgmDriver1IN2Pin, OUTPUT);
    pinMode(mgmDriver1ENAPin, OUTPUT);
    pinMode(mgmDriver1ENBPin, OUTPUT);

    pinMode(mgmDriver2IN1Pin, OUTPUT);
    pinMode(mgmDriver2IN2Pin, OUTPUT);
    pinMode(mgmDriver2ENAPin, OUTPUT);
    pinMode(mgmDriver2ENBPin, OUTPUT);

    // Wann ist digitalRead(microSwitchPin) HIGH?
    //
    // Das hängt davon ab, wie du den Schalter angeschlossen hast:
    // 1️⃣ Falls du COM mit GND und NO mit dem Arduino-Pin verbindest (übliche Variante)
    //
    //    Nicht betätigt: digitalRead(microSwitchPin) == LOW
    //    Betätigt: digitalRead(microSwitchPin) == HIGH
    //
    // 2️⃣ Falls du COM mit 5V und NC mit dem Arduino-Pin verbindest
    //
    //    Nicht betätigt: digitalRead(microSwitchPin) == HIGH
    //    Betätigt: digitalRead(microSwitchPin) == LOW
    //
    // Empfohlene Schaltung mit Pull-Up-Widerstand
    //
    // Da Mikroschalter oft prellen (kurze Störimpulse beim Schalten), sollte man den Eingang sauber halten.
    // Die gängigste Methode ist die Verwendung des internen Pull-Up-Widerstands von Arduino:

    pinMode(microSwitch1Pin, INPUT_PULLUP);
    pinMode(microSwitch2Pin, INPUT_PULLUP);
    pinMode(microSwitch3Pin, INPUT_PULLUP);
    pinMode(microSwitch4Pin, INPUT_PULLUP);

    pinMode(servoMotorPin, OUTPUT);

}

RoboticArm robot;
FSMRoboticArm fsm(robot);

void loop() {
    robot.updateSensors();
    fsm.evalTransition();
    fsm.evalState();
    robot.updateActuators();
}
