#include <Arduino.h>
#include <StatusLed.hpp>
#include <IrReader/IrReader.hpp>

#define IR_SENSOR 2
#define IR_SENSOR_INT_NUM 0
#define IR_LED 13
#define STATUS_LED 4

StatusLed statusLed(STATUS_LED);
IrReader irReader;

void setup()
{
    Serial.begin(9600);
    Serial.println("READING..");
    irReader.begin(IR_SENSOR, IR_SENSOR_INT_NUM);
}

void loop()
{
    Serial.println(irReader.getRecordedCode()->length);
    // if(irReader.isDecoded())
    // {
    //     Serial.println("[i] An valid code has been readed.");
    //     Serial.print("Length: ");
    //     Serial.println(irReader.getRecordedCode()->length);
    //     Serial.println("Code:");
    //     statusLed.setFor(StatusLedMode::OK, 1000);
    //     irReader.resume();
    // }
    // statusLed.update();
    irReader.update();
}
