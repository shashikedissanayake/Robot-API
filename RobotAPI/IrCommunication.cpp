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
		//Serial.println("start decoring");
		uint16_t output = -1;//Can't decord message
        if(recv->decode(&results)){
             if(results.bits >12){
                     output = -2;//message corrupted
             }else{
                     
                     output = results.value;
             }
        }
		recv->resume();
		Serial.println(results.value,HEX);
        return output;
}

