//
// Created by USER on 1/6/2019.
//

#ifndef ROBOT_API_IRCOMMUNICATION_H
#define ROBOT_API_IRCOMMUNICATION_H


#include <stdint-gcc.h>
#include "utility/IRremote.h"
#include "Arduino.h"

class IrCommunication {

public:
    const uint8_t MESSAGE_SIZE = 12;

    bool sendMessage(uint16_t data);
    bool sendMessageACK(uint16_t data);
    uint16_t reveiveMessage(IRrecv* recv);

private:
    IRsend iRsend;

};


#endif //ROBOT_API_IRCOMMUNICATION_H
