#include <Arduino.h>
#include "IRremoteESP8266.h"

int PIN_RECV = D0;

// IRrecv recv(PIN_RECV);
void setup()
{
    Serial.begin(115200);
    pinMode(PIN_RECV, OUTPUT);
    Serial.println("Ready Player One");
}

void loop()
{
    delay(500);
    Serial.println("OFF");
    digitalWrite(PIN_RECV, HIGH);
    delay(500);
    Serial.println("ON");
    digitalWrite(PIN_RECV, LOW);
    if (Serial.available())
    {
        int newpin = Serial.parseInt();
        if (newpin != PIN_RECV)
        {
            PIN_RECV = newpin;
            Serial.print("New pin: ");
            Serial.println(PIN_RECV);
            pinMode(PIN_RECV, OUTPUT);
        }
    }
}
