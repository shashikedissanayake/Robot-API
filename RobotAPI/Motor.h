//
// Created by USER on 11/6/2018.
//

#ifndef ROBOT_API_MOVE_H
#define ROBOT_API_MOVE_H

#include <stdint-gcc.h>
#include "Arduino.h"


class Motor {
public:
    Motor(int speedPinL,int speedPinR,int direcPinl1,int direcPinl2,int direcPinR1,int direcPinR2);
    void motorForward(uint8_t speed);
    void motorBackward(uint8_t speed);
    void motorstop();
    void motorTurnRight(int angle);
    void motorTurnLeft(int angle);
private:
    uint8_t _speedPinL;
    uint8_t _speedPinR;
    uint8_t _direcPinl1;
    uint8_t _direcPinl2;
    uint8_t _direcPinR1;
    uint8_t _direcPinR2;
};


#endif //ROBOT_API_MOVE_H
