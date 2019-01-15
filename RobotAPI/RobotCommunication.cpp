//
// Created by USER on 1/6/2019.
//

#include <stdint-gcc.h>
//----receiver pins---------------------//
uint8_t RCV_0 = 7;
uint8_t RCV_1 = 8;
uint8_t RCV_2 = 9;


//----operation codes for communication----//
//BASIC MESSAGES(NO ACKNOLEDGEMENT)
const uint16_t SEND_ID = 0x0100;
const uint16_t FOLLOW_ME = 0x0200;
const uint16_t COME_NEAR = 0x0300;

//ACKNOLEDGEMENT-BASED MESSAGES
const uint16_t TALK_REQUEST = 0x0800;
const uint16_t END_TALK = 0x0900;
const uint16_t SEND_DATA = 0x0A00;
const uint16_t MOTOR_SPEED = 0x0B00;
const uint16_t DEFINE_MASTER = 0x0C00;
//-----------------------------------------//

//ACK message
const int ACK = 0x00FF;

#include "RobotCommunication.h"
#include "Arduino.h"
//#include <ctime>

// variables that are use both ISR and RobotCommunication Class
const int RCV_COUNT = 3;
IRrecv* recvs[RCV_COUNT];
IrCommunication communicater;
uint16_t data[RCV_COUNT];
bool receved[RCV_COUNT];
volatile static bool read;

RobotCommunication::RobotCommunication() {
	Serial.println("Initializing");
	
    recvs[0] = new IRrecv(RCV_0);
    recvs[1] = new IRrecv(RCV_1);
    recvs[2] = new IRrecv(RCV_2);

    enableReceivers();
}

void RobotCommunication::sendMessage_sendid(uint8_t message) {
    uint16_t mess = SEND_ID | message ;
    communicater.sendMessage(mess);
    delay(100);
    enableReceivers();
}

void RobotCommunication::sendMessage_followme(uint8_t message) {
    uint16_t mess = FOLLOW_ME | message ;
    communicater.sendMessage(mess);
    delay(100);
    enableReceivers();
}

void RobotCommunication::sendMessage_comenear(uint8_t message) {
    uint16_t mess = COME_NEAR | message ;
    communicater.sendMessage(mess);
    delay(100);
    enableReceivers();
}

void RobotCommunication::receiveMessages() {
	cli();
    TCCR1A = 0;// set entire TCCR1A register to 0
    TCCR1B = 0;// same for TCCR1B
    TCNT1  = 0;//initialize counter value to 0
    // set compare match register for 1hz increments
    OCR1A = 31249;// ocr1a = [(16*10^6) / (256*(1/500ms))] - 1 (must be <65536)
    // turn on CTC mode
    TCCR1B |= (1 << WGM12);
    TCCR1B &= ~(1 << WGM13);
    // Set CS12  bits for 256 prescaler
    TCCR1B |= (1 << CS12);
    TCCR1B &= ~(1 << CS11);
    TCCR1B &= ~(1 << CS10);
    // enable timer compare interrupt
    TIMSK1 |= (1 << OCIE1A);
    sei();
    
}

ISR(TIMER1_COMPA_vect){
	read = true;
      for(int i=0;i<RCV_COUNT;i++){
		  uint16_t val = communicater.reveiveMessage(recvs[i]);
            switch(val){
				case 5000:
					receved[i] = false;
					break;
				case 5001:
					receved[i] = false;
					break;
				default:
					receved[i] = true;
					data[i] = val;
			}
        }  
		
}

void RobotCommunication::enableReceivers() {
    for(int i=0;i<RCV_COUNT;i++){
        recvs[i]->enableIRIn();
    }
}