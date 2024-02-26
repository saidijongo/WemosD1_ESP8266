#include <ESP8266WebServer.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>

// GPIO mappings for Arduino Wemos D1
int blue_Hall_U = 3;   // Hall sensor U
int green_Hall_V = 4;  // Hall sensor V
int yellow_Hall_W = 5; // Hall sensor W
int blue_U = 8;        // Control wire U
int green_V = 7;       // Control wire V
int yellow_W = 6;      // Control wire W

void setup() {
  // Initialize the pins
  pinMode(blue_Hall_U, INPUT);
  pinMode(green_Hall_V, INPUT);
  pinMode(yellow_Hall_W, INPUT);
  pinMode(blue_U, OUTPUT);
  pinMode(green_V, OUTPUT);
  pinMode(yellow_W, OUTPUT);

  // Set initial motor direction (CW)
  digitalWrite(blue_U, HIGH);
  digitalWrite(green_V, LOW);
  digitalWrite(yellow_W, LOW);
}

void loop() {
  // Rotate motor CW for 10 seconds
  rotateMotorCW(10000);

  // Rotate motor CCW for 10 seconds
  rotateMotorCCW(10000);
}

void rotateMotorCW(unsigned long duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    // Set motor direction (CW)
    digitalWrite(blue_U, HIGH);
    digitalWrite(green_V, LOW);
    digitalWrite(yellow_W, LOW);
  }
}

void rotateMotorCCW(unsigned long duration) {
  unsigned long startTime = millis();
  while (millis() - startTime < duration) {
    // Set motor direction (CCW)
    digitalWrite(blue_U, LOW);
    digitalWrite(green_V, LOW);
    digitalWrite(yellow_W, HIGH);
  }
}
