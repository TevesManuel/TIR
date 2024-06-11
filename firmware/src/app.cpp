#include <Arduino.h>
#include <StatusLed/StatusLed.hpp>
#include <DataVec/DataVec.hpp>

#define IR_SENSOR 8
#define IR_LED 13
#define STATUS_LED 4

StatusLed statusLed(STATUS_LED);

unsigned long last_1 = 0;

void setup()
{
    Serial.begin(9600);
    pinMode(IR_SENSOR, INPUT);
    DataVec<int> registerOfSecuence;
    registerOfSecuence.add(5);
    // mainNode = Node::begin();
    // Node::add(mainNode, 5);
    // Node::add(mainNode, 6);
    // Node::add(mainNode, 8);
    // Node::add(mainNode, 7);
    // Node::printAll(mainNode);
}

void loop()
{
    // if(digitalRead(IR_SENSOR))
    // {
    //     while(micros() > last_1 + 1000)
    //     {

    //         last_1 = micros();
    //     }
    // }
    // statusLed.update();
}
