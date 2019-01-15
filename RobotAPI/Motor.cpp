//
// Created by USER on 11/6/2018.
//
#include "Arduino.h"
#include "Motor.h"

Motor::Motor(int speedPinL, int speedPinR, int direcPinl1, int direcPinl2, int direcPinR1, int direcPinR2) {
    pinMode(speedPinL, OUTPUT);
    pinMode(speedPinR, OUTPUT);
    pinMode(direcPinl1, OUTPUT);
    pinMode(direcPinl2, OUTPUT);
    pinMode(direcPinR1, OUTPUT);
    pinMode(direcPinR2, OUTPUT);
    this->_speedPinL = speedPinL;
    this->_speedPinR = speedPinR;
    this->_direcPinl1 = direcPinl1;
    this->_direcPinl2 = direcPinl2;
    this->_direcPinR1 = direcPinR1;
    this->_direcPinR2 = direcPinR2;
}

void Motor::motorForward(uint8_t speed) {
    uint8_t speedMap = speed/10*255;
    analogWrite(_speedPinL, speedMap);//Sets speed variable via PWM
    digitalWrite(_direcPinl1, HIGH);
    digitalWrite(_direcPinl2, LOW);
    Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
    Serial.println("   "); // Creates a blank line printed on the serial monitor
    analogWrite(_speedPinR, speedMap);
    digitalWrite(_direcPinR1, LOW);
    digitalWrite(_direcPinR2, HIGH);
    Serial.println("Motor 2 Forward");
    Serial.println("   ");
}

void Motor::motorBackward(uint8_t speed) {
    uint8_t speedMap = speed/10*255;
    analogWrite(_speedPinL, speedMap);//Sets speed variable via PWM
    digitalWrite(_direcPinl1, LOW);
    digitalWrite(_direcPinl2, HIGH);
    Serial.println("Motor 1 Backward"); // Prints out “Motor 1 Forward” on the serial monitor
    Serial.println("   "); // Creates a blank line printed on the serial monitor
    analogWrite(_speedPinR, speedMap);
    digitalWrite(_direcPinR1, HIGH);
    digitalWrite(_direcPinR2, LOW);
    Serial.println("Motor 2 Backward");
    Serial.println("   ");
}

void Motor::motorstop() {

    analogWrite(_speedPinL, 0);//Sets speed variable via PWM
    digitalWrite(_direcPinl1, LOW);
    digitalWrite(_direcPinl2, HIGH);
    Serial.println("Motor 1 Stopped"); // Prints out “Motor 1 Forward” on the serial monitor
    Serial.println("   "); // Creates a blank line printed on the serial monitor
    analogWrite(_speedPinR, 0);
    digitalWrite(_direcPinR1, HIGH);
    digitalWrite(_direcPinR2, LOW);
    Serial.println("Motor 2 Stopped");
    Serial.println("   ");

}

void Motor::motorTurnRight(int angle) {
    int speedMap = 5/10*255;


}

void Motor::motorTurnLeft(int angle) {
    int speedMap = 5/10*255;
}
