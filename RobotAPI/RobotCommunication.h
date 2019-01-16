//
// Created by USER on 1/6/2019.
//
#ifndef ROBOT_API_ROBOTCOMMUNICATION_H
#define ROBOT_API_ROBOTCOMMUNICATION_H

#include "utility/IRremote.h"
#include "IrCommunication.h"
#include "Arduino.h"


class RobotCommunication {
public:
	
	RobotCommunication();
    void sendMessage_sendid(uint8_t message);
    void sendMessage_followme(uint8_t message);
    void sendMessage_comenear(uint8_t message);
    void receiveMessages();
private:
    void enableReceivers();
};


#endif //ROBOT_API_ROBOTCOMMUNICATION_H


