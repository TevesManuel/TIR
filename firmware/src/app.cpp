#include <Arduino.h>
#include <StatusLed.hpp>
#include <IrReader/IrReader.hpp>

#define IR_SENSOR 2
#define IR_SENSOR_INT_NUM 0
#define IR_LED 6
#define STATUS_LED 13

StatusLed statusLed(STATUS_LED);
IrReader irReader;

void setup()
{
    Serial.begin(9600);
    Serial.println("READING..");
    irReader.begin(IR_SENSOR, IR_SENSOR_INT_NUM);
}

#include<string.h>

void logInfo()
{
    Serial.print("isDecoded: ");
    Serial.println(irReader.isDecoded());
    Serial.println("RecordedCode:");
    Serial.print("\tLength: ");
    Serial.println(irReader.getRecordedCode()->length);
    Serial.println("CODE:");
    Snapshot * snapshot = new Snapshot;
    int i = 1;
    unsigned int total = 0;
    while(irReader.getRecordedCode()->iter(snapshot))
    {
        total = total + snapshot->pulseTime;
        // Serial.print("Pulse time: ");
        // Serial.print(snapshot->pulseTime);
        // Serial.println("us");
        // Serial.print("TOTAL TIME: ");
        // Serial.print(total);
        // Serial.println("us");
        Serial.print(snapshot->pulseTime);
        Serial.print(" ");
        if(i % 4 == 0)
        {
            Serial.println("");
        }
        i++;
    }
    irReader.getRecordedCode()->resetIter();

    Serial.print("Total time: ");
    Serial.println(total);
}

void loop()
{
    if(Serial.available())
    {
        Serial.println("");
        Serial.print("(");
        Serial.print(micros());
        Serial.println("us)");
        Serial.println("[i]");
        Serial.println("----------------------------------------");
        char op = (char)toupper(Serial.read());
        if( op == 'I' )
        {
            logInfo();
        }
    //     else if( op == 'O' )
    //     {
    //         irReader.resume();
    //         Serial.println("irReader is cleaned.");
    //     }
        Serial.println("\n----------------------------------------");
        Serial.println("");
    }
//     // if(irReader.isDecoded())
//     // {
//     // //     Serial.println("[i] An valid code has been readed.");
//     // //     Serial.print("Length: ");
//     // //     Serial.println(irReader.getRecordedCode()->length);
//     // //     Serial.println("Code:");
//     // //     statusLed.setFor(StatusLedMode::OK, 1000);
//     // //     irReader.resume();
//     // }
    statusLed.update();
    irReader.update();
}
