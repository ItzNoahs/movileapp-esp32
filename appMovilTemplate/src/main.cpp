#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;

#define ONBOARD_LED 2

int incoming;

void setup() {
  // put your setup code here, to run once:
  ESP_BT.begin("ESP_APP");
  pinMode(ONBOARD_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ESP_BT.available()) {
    incoming = ESP_BT.read();
  }
  switch (incoming) {
  case 0:
    digitalWrite(ONBOARD_LED, LOW);
    break;
  case 1:
    digitalWrite(ONBOARD_LED, HIGH);
    break;
  }
}
