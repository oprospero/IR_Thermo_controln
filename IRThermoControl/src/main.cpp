#define BLYNK_PRINT Serial
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "IRremoteESP8266.h"
#include "BlynkSimpleEsp8266.h"


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "3771a29413a54d7387eaae537228ed95";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "HouseOfMack_EXT";
char pass[] = "SeanSaraMack123";

#define IR_LED_PIN D0

// IRsend IrOut(IR_LED_PIN);


void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // IrOut.begin();
  Serial.println("Ready Player One");
  pinMode(D0, OUTPUT);
  digitalWrite(D0, HIGH);
}

BLYNK_WRITE(V0)
{
    bool value = param.asInt();
    digitalWrite(D0, value);
}

void loop()
{

  Blynk.run();
}
