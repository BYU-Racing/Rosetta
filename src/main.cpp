#include <Arduino.h>
#include <Rosetta.h>
constexpr int BEGIN = 9600;
constexpr int BAUDRATE = 250000;


FlexCAN_T4<CAN1, RX_SIZE_256, TX_SIZE_16> can1;
FlexCAN_T4<CAN2, RX_SIZE_256, TX_SIZE_16> can2;

Rosetta rosetta(&Serial2);

void setup() {
  Serial.begin(9600);
  Serial2.begin(115200);

  can1.begin();
  can1.setBaudRate(BAUDRATE);
  can2.begin();
  can2.setBaudRate(BAUDRATE);

  rosetta.setCAN(can2, can1);
}

void loop() {
  rosetta.run();
}
