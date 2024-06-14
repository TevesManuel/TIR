#include <Arduino.h>
#include <StatusLed.hpp>
#include <IrReader/IrReader.hpp>

#define IR_SENSOR 2
#define IR_SENSOR_INT_NUM 0
#define IR_LED 13//7
#define STATUS_LED 4//13

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
    Serial.print("(");
    Serial.print(micros());
    Serial.println("us)");
    Serial.println("[i]");
    Serial.println("----------------------------------------");
    Serial.print("isDecoded: ");
    Serial.println(irReader.isDecoded());
    Serial.println("RecordedCode:");
    Serial.print("\tLength: ");
    Serial.println(irReader.getRecordedCode()->length);
    Serial.println("CODE:");
    Snapshot * snapshot;
    int i = 1;
    while(irReader.getRecordedCode()->iter(snapshot))
    {
        Serial.print(snapshot->atTime);
        Serial.print(" ");
        if(i % 4 == 0)
        {
            Serial.println("");
        }
        i++;
    }
    Serial.println("----------------------------------------");
}

void loop()
{
    // logInfo();
//     // if(Serial.available())
//     // {
//     //     Serial.println("");
//     //     if( (char)toupper(Serial.read()) == 'I' )
//     //     {
//     //         logInfo();
//     //     }
//     //     Serial.println("");
//     // }
//     // if(irReader.isDecoded())
//     // {
//     // //     Serial.println("[i] An valid code has been readed.");
//     // //     Serial.print("Length: ");
//     // //     Serial.println(irReader.getRecordedCode()->length);
//     // //     Serial.println("Code:");
//     // //     statusLed.setFor(StatusLedMode::OK, 1000);
//     // //     irReader.resume();
//     // }
//     // statusLed.update();
//     // irReader.update();
}
