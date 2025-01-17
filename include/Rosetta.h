#ifndef ROSETTA_H
#define ROSETTA_H

#include "FlexCAN_T4.h"
#include "SerialTransfer.h"

class Rosetta {

    private:
        HardwareSerial* uSerial;
        CAN_message_t msg;
        FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> comsCAN;
        FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> motorCAN;
        SerialTransfer transferTool;


    public:
        Rosetta(HardwareSerial* serialIn);


        void run();

        void translate();

        void setCAN(FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> comsCANin, FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> motorCANin);
};


#endif