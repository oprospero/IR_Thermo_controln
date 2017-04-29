#include <Arduino.h>

unsigned long previous = 0;
int lastState = LOW;
unsigned int codes[256];
int x = 0;

void setup()
{
    Serial.begin(115200);
    pinMode(D1, INPUT);
}


void loop()
{
    int state = digitalRead(D1);
    if (state != lastState)
    {
        lastState = state;
        unsigned long current = micros();
        unsigned long diff = current - previous;

        int r = diff;
        if (r < 300 || r > 1500) Serial.println(r);
        else if (state == HIGH)
        {
            Serial.print(r);
            Serial.print("-");
        }
        else{
            Serial.print(r);
            Serial.print(", ");
        }


        previous = current;
    }

    // if (digitalRead(D1) == HIGH)
    // {
    //     unsigned long start = micros();
    //     while(digitalRead(D1) == HIGH) delay(0);
    //     unsigned long end = micros();
    //     unsigned long diff = end - start;
    //     codes[x++] = diff;
    // }
    //
    // if (digitalRead(D1) == LOW)
    // {
    //     unsigned long start = micros();
    //     while(digitalRead(D1) == LOW) delay(0);
    //     unsigned long end = micros();
    //     unsigned long diff = end - start;
    //     codes[x++] = diff;
    // }

    // if (codes[x] > 15000)
    // {
    //     for (int i = 0; i <= x; i++)
    //     {
    //         // int r = results.rawbuf[i];
    //         int r = codes[i];
    //         if (r < 300 || r > 1500) Serial.println(r);
    //         else if (i % 2 == 1)
    //         {
    //             Serial.print(r);
    //             Serial.print("-");
    //         }
    //         else{
    //             Serial.print(r);
    //             Serial.print(", ");
    //         }
    //     }
    //     x = 0;
    // }
}
