#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";

const char* homeAssistantUrl = "http://your_home_assistant_url:8123/api/states/sensor.garage_door";
const char* homeAssistantToken = "your_home_assistant_long_lived_access_token";

// Pin that garage door sensor is connected to
const int garageDoorPin = 4;

// State of garage door (0 = closed, 1 = open)
int garageDoorState = 0;

void setup() {
  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Set garage door pin as input
  pinMode(garageDoorPin, INPUT);

  // Read initial state of garage door
  garageDoorState = digitalRead(garageDoorPin);
}

void loop() {
  // Check if garage door state has changed
  int newState = digitalRead(garageDoorPin);
  if (newState != garageDoorState) {
    // Update garage door state
    garageDoorState = newState;

    // Send notification to Home Assistant
    sendNotificationToHomeAssistant();
  }
}

void sendNotificationToHomeAssistant() {
  HTTPClient http;

  String body = "{\"state\":\"";
  body += (garageDoorState == 0) ? "closed" : "open";
  body += "\"}";

  http.begin(homeAssistantUrl);
  http.addHeader("Content-Type", "application/json");
  http.addHeader("Authorization", "Bearer " + String(homeAssistantToken));
  int httpCode = http.PUT(body);

  if (httpCode > 0) {
    Serial.println(httpCode);
    Serial.println(http.getString());
  } else {
    Serial.println("Error sending notification to Home Assistant");
  }

  http.end();
}
