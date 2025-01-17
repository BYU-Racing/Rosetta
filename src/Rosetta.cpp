#include "Rosetta.h"


Rosetta::Rosetta(HardwareSerial* serialIn) {
    uSerial = serialIn;
}

struct Message {
    uint8_t id;
    uint8_t buf[8];
} message;


void Rosetta::run() {
    if(comsCAN.read(msg)) {
        translate();
    }

    if(motorCAN.read(msg)) {
        translate();
    }
}

void Rosetta::setCAN(FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> comsCANin, FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> motorCANin) {
    comsCAN = comsCANin;
    motorCAN = motorCANin;

    transferTool.begin(*uSerial);
}

void Rosetta::translate() {

    uint16_t sendSize = 0;

    message.id = msg.id;

    for(int i = 0; i < 8; i++) {
        message.buf[i] = msg.buf[i];
    }

    sendSize = transferTool.txObj(message, sendSize);

    transferTool.sendData(sendSize);
}