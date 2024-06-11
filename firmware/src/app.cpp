#include <Arduino.h>
#include <IRremote.h>
#include <StatusLed/StatusLed.hpp>

#define IR_SENSOR 8
#define LED 4
#define IR_LED 13

IRrecv irRecv(IR_SENSOR);
IRsend irSend(LED);
StatusLed statusLed(LED);

void setup()
{
    Serial.begin(9600);
    irRecv.enableIRIn();
}

void loop()
{
    if (irRecv.decode())
    {
        Serial.print("LEN");
        Serial.println(irRecv.decodedIRData.rawDataPtr->rawlen, DEC);
        float periodo = 0;
        for(int i = 0; i < irRecv.decodedIRData.rawDataPtr->rawlen; i++)
        {
            Serial.print(irRecv.decodedIRData.rawDataPtr->rawbuf[i]);
            Serial.print(" ");
            periodo += irRecv.decodedIRData.rawDataPtr->rawbuf[i];
        }
        periodo = periodo / 1000000; // to us
        Serial.println("");
        Serial.print("periodo: ");
        Serial.print(periodo);
        Serial.print(" freq: ");
        Serial.println(1.0/periodo);
        irRecv.printIRResultRawFormatted(&Serial);
        // Serial.println(irRecv.decodedIRData.decodedRawData);
        // irSend.sendRaw(irRecv.decodedIRData.decodedRawData, )
        irRecv.resume();
        statusLed.setFor(StatusLedMode::OK, 1000);
    }
    statusLed.update();
}
