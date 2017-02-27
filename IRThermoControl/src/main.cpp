
#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <ESP8266WiFi.h>
#include "BlynkSimpleEsp8266.h"

#define IR_LED_PIN 1

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "HouseOfMack_EXT";
char pass[] = "SeanSarahMack123";

IRsend IrOut(IR_LED_PIN);

void setup()
{

}

void loop()
{

}
