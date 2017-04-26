#include <Arduino.h>
#include "IRremoteESP8266.h"

#define PIN_IR_INPUT D2
IRrecv recv();


void setup()
{
    Serial.begin(115200);
    Serial.print("D0: "); Serial.println(D0);
    Serial.print("D1: "); Serial.println(D1);
    Serial.print("D2: "); Serial.println(D2);
    Serial.print("D3: "); Serial.println(D3);
    Serial.print("D4: "); Serial.println(D4);
    Serial.print("D6: "); Serial.println(D6);
    Serial.print("D7: "); Serial.println(D7);
    Serial.print("D8: "); Serial.println(D8);
    Serial.print("D9: "); Serial.println(D9);
    Serial.print("D10: "); Serial.println(D10);
}

void loop()
{

}
