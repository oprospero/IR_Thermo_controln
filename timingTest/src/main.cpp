#include <Arduino.h>

unsigned long previous = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(D1, INPUT);
}


void loop()
{
    if (digitalRead(D1) == HIGH)
    {
        unsigned long start = micros();
        while(digitalRead(D1) == HIGH);
        unsigned long end = micros();
        Serial.print("On: ");
        Serial.println(end - start);
    }

    if (digitalRead(D1) == LOW)
    {
        unsigned long start = micros();
        while(digitalRead(D1) == LOW);
        unsigned long end = micros();
        Serial.print("OFF: ");
        Serial.println(end - start);
    }


}
