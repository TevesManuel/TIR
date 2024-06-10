#include <Arduino.h>
#include <IRremote.h>

#define IR_SENSOR 8
#define LED 13

IRrecv irRecv(IR_SENSOR);

struct LEDOUT
{
    int pulseWidth;
    int periodWidth;
    int targetTimes;
    int actualTimes;
    unsigned long lastModification;
} LEDOUT;

void LEDOUT_RESET()
{
    LEDOUT.pulseWidth = 10;
    LEDOUT.periodWidth = 10;
    LEDOUT.targetTimes = 3;
    LEDOUT.actualTimes = 0;
    LEDOUT.lastModification = 0;
}

void setup()
{
    Serial.begin(9600);

    irRecv.enableIRIn();
    pinMode(LED, OUTPUT);
}

void loop()
{
    if (irRecv.decode()) {
        Serial.println(irRecv.decodedIRData.decodedRawData, HEX);
        irRecv.resume();
    }
    if (LEDOUT.actualTimes < LEDOUT.targetTimes) // Is active?
    {
        if
    }
}
