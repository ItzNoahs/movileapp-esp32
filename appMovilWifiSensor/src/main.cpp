/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit
 * https://esp32io.com/tutorials/esp32-web-server
 */

#include "index.h" // Include the index.h file
#include <ESPAsyncWebServer.h>
#include <WiFi.h>

const char *ssid = ""; // CHANGE IT
const char *password = "";    // CHANGE IT

AsyncWebServer server(80);

#define SENSOR_PIN 18
int value = 0;

int getSensor() {
  value = digitalRead(SENSOR_PIN);
  if (value == HIGH) {
    return 1;
  } else {
    return 0;
  }
}

void setup() {
  pinMode(SENSOR_PIN, INPUT);

  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Print the ESP32's IP address
  Serial.print("ESP32 Web Server's IP address: ");
  Serial.println(WiFi.localIP());

  // Serve the HTML page from the file
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("ESP32 Web Server: New request received:"); // for debugging
    Serial.println("GET /");                                   // for debugging

    request->send(200, "text/html", webpage);
  });

  // Define a route to get the temperature data
  server.on("/infrared", HTTP_GET, [](AsyncWebServerRequest *request) {
    Serial.println("ESP32 Web Server: New request received:"); // for debugging
    Serial.println("GET /infrared");                           // for debugging
    int infrared = getSensor();
    // Format the temperature with two decimal places
    if (infrared == 1) {
      request->send(200, "text/plain", "Detectado!");
    } else {
      request->send(200, "text/plain", "No Detectado");
    }
  });

  // Start the server
  server.begin();
}

void loop() {
  // Your code here
}
