//
// Created by USER on 11/6/2018.
//

#include "SerialCommunication.h"
/*
SerialCommunication::SerialCommunication(uint8_t rx, uint8_t tx) {
    serial = new SoftwareSerial(rx,tx);
    serial->begin(9600);
}

void SerialCommunication::serialWrite(String message) {
    serial->print(message);
}

char SerialCommunication::serialReadAfterWrite(String message) {
    serial->print(message);
    char temp;
    while(serial->available()>0){
        temp = serial->read();
        break;
    }
    return temp;
}
*/