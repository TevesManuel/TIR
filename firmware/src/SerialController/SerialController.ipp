#include <SerialController/SerialController.hpp>
#include <Arduino.h>
#include <utils/utils.hpp>
#include <string.h>

#define SERIAL_BAUD_RATE 9600
#define SERIAL_EMISSION_DELAY 250

SerialController::SerialController()
{
}
void SerialController::begin(IrReader * irReaderRef)
{
    Serial.begin(SERIAL_BAUD_RATE);
    this->lastSerialEmission = 0;
    this->irReaderRef = irReaderRef;
    Serial.println("[i] Serial controller has been initialized.");
}

#include<IrReader/IrReader.hpp>
#include<Snapshot.hpp>

void SerialController::logInfo()
{
    if(this->irReaderRef != nullptr)
    {
        Serial.print("isDecoded: ");
        Serial.println(this->irReaderRef->isDecoded());
        Serial.println("RecordedCode:");
        Serial.print("\tLength: ");
        Serial.println(this->irReaderRef->getRecordedCode()->length);
        Serial.println("CODE:\n\t");
        Snapshot * snapshot = new Snapshot;
        int i = 1;
        unsigned int total = 0;
        while(this->irReaderRef->getRecordedCode()->iter(snapshot) != nullptr)
        {
            total = total + snapshot->pulseTime;
            Serial.print(snapshot->pulseTime);
            Serial.print(" ");
            if(i % 4 == 0)
            {
                Serial.print("\n\t");
            }
            i++;
        }

        Serial.print("\nTotal time: ");
        Serial.println(total);
    }
    else
    {
        Serial.println("[!] IrReader is not defined.");
    }
}

void SerialController::update()
{
    if(Serial.available())
    {
        char op = (char)toupper(Serial.read());
        if(TUtils::elapsed(this->lastSerialEmission) > SERIAL_EMISSION_DELAY)
        {
            this->lastSerialEmission = micros();
            Serial.println("");
            Serial.print("(");
            Serial.print(micros());
            Serial.println("us)");
            Serial.println("[i]");
            Serial.println("----------------------------------------");
            if( op == 'I' )
            {
                this->logInfo();
            }
            else if( op == 'O' )
            {
                Serial.println("Cleaning irReader...");
                this->irReaderRef->resume();
                Serial.println("irReader is cleaned.");
            }
            Serial.println("\n----------------------------------------");
            Serial.println("");
        }
    }
}