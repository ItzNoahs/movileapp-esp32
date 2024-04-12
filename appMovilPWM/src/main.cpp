#include "BluetoothSerial.h"
BluetoothSerial ESP_BT;

#define ONBOARD_LED 2
#define PWM_GPIO 18

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

int incoming;

void setup() {
  // put your setup code here, to run once:
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
  }
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }
}
