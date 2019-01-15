//
// Created by USER on 1/6/2019.
//

#include "IrCommunication.h"

bool IrCommunication::sendMessage(uint16_t data) {
    this->iRsend.sendSony(data, MESSAGE_SIZE);
    return true;
}

bool IrCommunication::sendMessageACK(uint16_t data) {
    this->iRsend.sendSony(data,MESSAGE_SIZE);
    return true;
}

uint16_t IrCommunication::reveiveMessage(IRrecv *recv) {
        decode_results results;
        if(recv->decode(&results)){
             if(results.bits >12){
                     return 5000;//message corrupted
             }else{
                     recv->resume();
					 Serial.println(results.value,HEX);
                     return results.value;
             }
        }

        return 5001;//Can't decord message
}

