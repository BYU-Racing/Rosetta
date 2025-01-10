#include "Rosetta.h"


Rosetta::Rosetta(HardwareSerial* serialIn) {
    uSerial = serialIn;
}


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
}

void Rosetta::translate() {
    
    char serialMessage[12]; // 1 newline + 1 ID + 8 buffers + 1 null terminator

    serialMessage[0] = '\n';

    serialMessage[1] = static_cast<char>(msg.id);

    for (int i = 0; i < 8; i++) {
        serialMessage[i + 2] = static_cast<char>(msg.buf[i]);
    }

    serialMessage[10] = '\0';

    uSerial->write(serialMessage, 10); 
}