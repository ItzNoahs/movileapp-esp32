#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;

#define ONBOARD_LED 2
#define PWM_GPIO 18

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

int incoming = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  ESP_BT.begin("ESP_APP");
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(PWM_GPIO, ledChannel);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (ESP_BT.available()) {
    incoming = ESP_BT.read();
    Serial.println(incoming);
  }

  ledcWrite(ledChannel, incoming);
  delay(50);
}
