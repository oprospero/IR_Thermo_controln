#include <Arduino.h>
#include "IRremoteESP8266.h"

#define PIN_IR_INPUT D1
#define PIN_IR_OUTPUT D0
IRrecv recv(PIN_IR_INPUT);
IRsend snd(PIN_IR_OUTPUT);
decode_results results;
unsigned int codes[256];
const int st = 450;
const int lt = 1300;
const int et = 8100;
unsigned int codeTimer[] =
{
    lt, st,
    lt, st,
    st, lt,
    lt, st,
    lt, st,
    st, lt,
    st, lt,
    st, lt,
    st, lt,
    st, lt,
    lt, st,
    st, et
};

void setup()
{
    Serial.begin(115200);
    recv.enableIRIn(); // Start the receiver
    snd.begin();
    Serial.println("Ready Player One");
}

void copyCode(volatile unsigned int* values, int length)
{
    for(int i = 0; i < length; i++)
    {
        codes[i] = values[i] * 50;
    }
}

void loop()
{
    if (recv.decode(&results))
    {

        copyCode(results.rawbuf, results.rawlen);
        for (int i = 0; i < results.rawlen; i++)
        {
            // int r = results.rawbuf[i];
            int r = codes[i];
            if (r < st - 100 || r > lt + 100) Serial.println(r);
            else if (i % 2 == 1)
            {
                Serial.print(r);
                Serial.print("-");
            }
            else{
                Serial.print(r);
                Serial.print(", ");
            }
        }
        delay(2000);
        snd.sendRaw(codes, results.rawlen, 38);
        Serial.println();
        // Serial.println(results.value, HEX);
        recv.resume(); // Receive the next value
    }
    delay(100);
    snd.sendRaw(codeTimer, 24, 38);
    snd.sendRaw(codeTimer, 24, 38);
    snd.sendRaw(codeTimer, 24, 38);
    snd.sendRaw(codeTimer, 24, 38);
    delay(1000);
}
