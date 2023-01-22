## Garage Door Notification for Home Assistant

This is a simple Arduino sketch for the ESP32 that detects the state of a garage door and sends a notification to Home Assistant when the state changes.
Requirements

    ESP32 board
    A garage door sensor
    A Wi-Fi connection
    A Home Assistant instance set up and configured to receive RESTful API calls
    An authentication method for the Home Assistant API (long-lived token, short-lived token, or secret key)

<img src="Images1\esp32.png" alt="ESP32 Image">


## Installation

    Connect the garage door sensor to a digital input pin of the ESP32
    Install the required libraries: WiFi.h, HTTPClient.h
    Open the sketch in the Arduino IDE
    Update the following constants with your own values:

    ssid: the SSID of your Wi-Fi network
    password: the password of your Wi-Fi network
    homeAssistantUrl: the URL of your Home Assistant instance (example: http://your_home_assistant_url:8123/api/states/sensor.garage_door)
    homeAssistantToken: the authentication token or secret key for the Home Assistant API
    garageDoorPin: the digital pin number that the garage door sensor is connected to

    Upload the sketch to the ESP32
    Open the Serial Monitor to check for any errors or issues during setup

## Usage

The sketch will automatically send a notification to Home Assistant when the state of the garage door sensor changes. The state of the sensor is based on the value read from the digital input pin and can be either 0 (closed) or 1 (open).

You can check the state of the garage door sensor in Home Assistant by going to the "States" page or by using the "Garage Door" sensor in your automations.
Note

    Make sure to use a secure connection for sending the notifications (HTTPS or a secure token)
    Make sure to use a meaningful name that describes the functionality of the code, as it will be easier to find and understand what the code does when you come back to it later.

This is just an example, you can modify it to suit your needs and add more functionalities.
