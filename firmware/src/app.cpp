#include <Arduino.h>
#include <StatusLed.hpp>
#include <IrReader/IrReader.hpp>
#include <SerialController/SerialController.hpp>

#define IR_SENSOR 2
#define IR_SENSOR_INT_NUM 0
#define IR_LED 6
#define STATUS_LED 13

StatusLed statusLed(STATUS_LED);
IrReader irReader;
SerialController serialController;

void setup()
{
    irReader.begin(IR_SENSOR, IR_SENSOR_INT_NUM);
    serialController.begin(&irReader);
}

void loop()
{
    if(irReader.isDecoded())
    {
        serialController.logInfo();
        // irReader.resume();
    }

    serialController.update();
    statusLed.update();
    irReader.update();
}
